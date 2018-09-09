#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 1024100;

string desc;
int n, seg[4 * N], lazy[4 * N];

void build(int p = 1, int l = 0, int r = n-1){

    if(l == r){
        seg[p] = desc[l] - '0';
        return;
    }

    int md = (l+r)/2;
    build(p*2, l, md);
    build(p*2+1, md+1, r);

    seg[p] = seg[p*2] + seg[p*2+1];
}

void propagating(int p, int l, int r){
    if(lazy[p] == 0) return;

    switch(lazy[p]){
        case 1: //barbary
            seg[p] = 0;
            break;
        case 2: //bucc
            seg[p] = r - l + 1;
            break;
        case 3: //reverse
            seg[p] = (r - l + 1) - seg[p];
            break;
    }

    if(l != r){
        if(lazy[p] == 3){
            lazy[p*2] = 3 - lazy[p*2];
            lazy[p*2+1] = 3 - lazy[p*2+1];
        } else{
            lazy[p*2] = lazy[p*2+1] = lazy[p];
        }
    }

    lazy[p] = 0;
}

void update(int a, int b, int action, int p = 1, int l = 0, int r = n-1){
    propagating(p, l, r);

    if(r < a or l > b) return;

    if(a <= l and r <= b){

        lazy[p] = action;
        propagating(p, l, r);
        return;
    }

    int md = (l+r)/2;
    update(a, b, action, p*2, l, md);
    update(a, b, action, p*2+1, md+1, r);

    seg[p] = seg[p*2] + seg[p*2+1];
}

int get(int a, int b, int p = 1, int l = 0, int r = n-1){

    if(r < a or l > b) return 0;

    propagating(p, l, r);

    if(a <= l and r <= b) return seg[p];

    int md = (l+r)/2;
    return get(a, b, p*2, l, md) 
        + get(a, b, p*2+1, md+1, r);
}

void solve(){

    desc = "";
    memset(lazy, 0, sizeof lazy);
    
    int m, t, l, r, cs = 0;
    char op, str[200];

    scanf("%d", &m);
    while(m-- > 0){
        scanf("%d%s", &t, str);
        while(t-- > 0) desc += str;
    }

    n = desc.size();
    build();

    scanf("%d", &m);
    while(m-- > 0){
        scanf(" %c%d%d", &op, &l, &r);

        if(op == 'F'){
            update(l, r, 2);
        } else if(op == 'E'){
            update(l, r, 1);
        } else if(op == 'I'){
            update(l, r, 3);
        } else if(op == 'S'){
            printf("Q%d: %d\n", ++cs, get(l, r));
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    int cs = 0, t;
    scanf("%d", &t);
    while(t-- > 0){
        printf("Case %d:\n", ++cs);
        solve();
    }

    return 0;
}