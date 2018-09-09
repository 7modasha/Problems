#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100100;

int n, root[N], L[4 * N], R[4 * N], seg[4 * N], nxt = 1;

void build(int p = root[0], int l = 1, int r = n){

    if(l == r){
        seg[p] = 1;
        return;
    }

    int md = (l+r)/2;
    L[p] = nxt++; R[p] = nxt++;

    build(L[p], l, md);
    build(R[p], md+1, r);

    seg[p] = seg[L[p]] + seg[R[p]];
}

int update(int idx, int val, int p, int l = 1, int r = n){
    int P = nxt++;

    if(l == r){
        seg[P] = val;
        return P;
    }

    int md = (l+r)/2;
    L[P] = L[p]; R[P] = R[p];

    if(idx <= md)
        L[P] = update(idx, val, L[p], l, md);
    else
        R[P] = update(idx, val, R[p], md+1, r);

    seg[P] = seg[L[P]] + seg[R[P]];

    return P;
}

int get(int a, int b, int p, int l = 1, int r = n){

    if(r < a or l > b) return 0;
    if(a <= l and r <= b) return seg[p];

    int md = (l+r)/2;
    return get(a, b, L[p], l, md) 
        + get(a, b, R[p], md+1, r);
}

int main(){
 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

    cin >> n;
    build();

    root[1] = update(1, 2, root[0]);

    cout << get(1, 1, root[1]) << endl;

    return 0;
}