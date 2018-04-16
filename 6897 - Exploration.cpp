#include <bits/stdc++.h>

using namespace std;

int n, k, f;

int fr[2100];
vector<vector<int> > g;

void dfs(int v){
	if(fr[v] < k)
		fr[v] = 0;
	else
		return;

	for(int i = 0; i < (int)g[v].size(); ++i){

		int u = g[v][i];

		if(fr[u] > 0){
			--fr[u];
			dfs(u);
		}
	}
}

void solve(){

	scanf("%d%d%d", &n, &k, &f);

	g.clear();
	g.resize(n);
	for(int i = 0, a, b; i < f; ++i){
		scanf("%d%d", &a, &b);
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 0; i < n; ++i)
		fr[i] = g[i].size();
	
	for(int i = 0; i < n; ++i)
		if(fr[i] > 0) dfs(i);

	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += (fr[i] >= k);

	printf("%d\n", ans);
}

int main(int argc, char const *argv[]){

	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t-- > 0) solve();
	
	return 0;
}