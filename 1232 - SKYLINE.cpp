#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100100;

struct node {
    int mn, mx, upd;
} seg[4 * N];

ll ans;

void update(int a, int b, int h, int p = 1, int l = 1, int r = N){

    if(seg[p].upd != 0){
        if(l != r){
            seg[p*2].mx = seg[p*2].mn = seg[p*2].upd = seg[p].upd;
            seg[p*2+1].mx = seg[p*2+1].mn = seg[p*2+1].upd = seg[p].upd;
        }
        seg[p].upd = 0;
    }

    if(r < a or l > b or seg[p].mn > h) return;

    if(a <= l and r <= b and h >= seg[p].mx){
        ans += (r-l+1);
        seg[p].mx = seg[p].mn = seg[p].upd = h;
        return;
    }

    int md = (l+r)/2;
    update(a, b, h, p*2, l, md);
    update(a, b, h, p*2+1, md+1, r);

    seg[p].mx = max(seg[p*2].mx, seg[p*2+1].mx);
    seg[p].mn = min(seg[p*2].mn, seg[p*2+1].mn);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    int t, n;
    scanf("%d", &t);
    while(t-- > 0){
        ans = 0;
        memset(seg, 0, sizeof seg);

        scanf("%d", &n);
        for(int i = 0, a, b, h; i < n; ++i){
            scanf("%d%d%d", &a, &b, &h);
            update(a, b-1, h);
        }

        printf("%d\n", ans);
    }
    
    return 0;
}