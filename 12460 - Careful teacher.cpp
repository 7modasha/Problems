#include <bits/stdc++.h>

using namespace std;

const int N = 20100;

string a[N];
int n, dsu[N];
map<string, int> mp;

int find(int x){
    return x == dsu[x] ? x : dsu[x] = find(dsu[x]);
}

void Union(int u, int v){

    u = find(u); v = find(v);
    if(u == v) return;
    dsu[u] = v;
}

int main(){
 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

    while(cin >> a[n] and a[n] != "--")
        mp[a[n]] = n++;
    
    for(int i = 0; i < n; ++i)
        dsu[i] = i;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(a[i].size() != a[j].size()) continue;

            int df = 0;
            for(int k = 0; k < a[i].size(); ++k)
                df += (a[i][k] != a[j][k]);

            if(df == 1)
                Union(mp[a[i]], mp[a[j]]);
        }
    }

    string x, y;
    while(cin >> x >> y){
        if(mp.count(x) and mp.count(y) and find(mp[x]) == find(mp[y]))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}