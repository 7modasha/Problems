#include <bits/stdc++.h>
#define ZERO 0
#define NEGATIVE 1
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100100;

string ans;
int n, k, arr[N], seg[2][4 * N];

void build(int p = 1, int l = 1, int r = n){

    if(l == r){
        if(arr[l] == 0)
            seg[ZERO][p] = 1;
        else if(arr[l] < 0)
            seg[NEGATIVE][p] = 1;
        else
            seg[ZERO][p] = seg[NEGATIVE][p] = 0;

        return;
    }

    int md = (l+r)/2;
    build(p*2, l, md);
    build(p*2+1, md+1, r);

    seg[0][p] = seg[0][p*2] + seg[0][p*2+1];
    seg[1][p] = seg[1][p*2] + seg[1][p*2+1];
}

void update(int idx, int val, int p = 1, int l = 1, int r = n){

    if(l == r){
        if(val == 0){
            seg[ZERO][p] = 1;
            seg[NEGATIVE][p] = 0;
        } else if(val < 0){
            seg[ZERO][p] = 0;
            seg[NEGATIVE][p] = 1;
        } else
            seg[ZERO][p] = seg[NEGATIVE][p] = 0;

        return;
    }

    int md = (l+r)/2;
    if(idx <= md)
        update(idx, val, p*2, l, md);
    else
        update(idx, val, p*2+1, md+1, r);

    seg[0][p] = seg[0][p*2] + seg[0][p*2+1];
    seg[1][p] = seg[1][p*2] + seg[1][p*2+1];
}

int get(int i, int a, int b, int p = 1, int l = 1, int r = n){

    if(r < a or l > b) return 0;

    if(a <= l and r <= b)return seg[i][p];

    int md = (l+r)/2;

    return get(i, a, b, p*2, l, md) 
        + get(i, a, b, p*2+1, md+1, r);
}

int main(){
 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    char op;
    int x, y;
    while(scanf("%d%d", &n, &k) != EOF){

        ans = "";
        memset(seg, 0, sizeof seg);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        build();

        while(k-- > 0){
            scanf(" %c%d%d", &op, &x, &y);

            if(op == 'C')
                update(x, y);
            else if(op == 'P'){
                
                if(get(ZERO, x, y) >= 1)
                    ans += '0';
                else if(get(NEGATIVE, x, y) % 2 == 0)
                    ans += '+';
                else
                    ans += '-';
            }
        }

        printf("%s\n", ans.c_str());
    }

    return 0;
}