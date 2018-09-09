#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100100;

map<int, int> mp;
int n, m, arr[N], rev[N], root[N], L[20 * N], R[20 * N], seg[20 * N], nxt = 1;

void build(int p = root[0], int l = 1, int r = n){

    if(l == r)
        return;

    int md = (l+r)/2;
    L[p] = nxt++; R[p] = nxt++;

    build(L[p], l, md);
    build(R[p], md+1, r);
}

int update(int idx, int p, int l = 1, int r = n){
    int P = nxt++;

    seg[P] = seg[p] + 1;
    if(l == r)
        return P;

    int md = (l+r)/2;
    L[P] = L[p]; R[P] = R[p];

    if(idx <= md)
        L[P] = update(idx, L[p], l, md);
    else
        R[P] = update(idx, R[p], md+1, r);

    return P;
}

int get(int a, int b, int k, int l = 1, int r = n){

    if(l == r)
        return l;

    int md = (l+r)/2;

    int cnt = seg[L[b]] - seg[L[a]];

    if(cnt >= k)
        return get(L[a], L[b], k, l, md);

    return get(R[a], R[b], k - cnt, md+1, r);
}

void compress(){

    for(int i = 1; i <= n; ++i)
        mp[arr[i]];
    
    int id = 1;
    for(auto &it : mp){
        it.second = id;
        rev[id] = it.first;
        ++id;
    }
}

int main(){
 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    build();

    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    compress();

    for(int i = 1; i <= n; ++i)
        root[i] = update(mp[arr[i]], root[i-1]);

    int a, b, k;
    while(m-- > 0){
        scanf("%d%d%d", &a, &b, &k);
        int x = get(root[a-1], root[b], k);
        printf("%d\n", rev[x]);
    }

    return 0;
}