#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

bool vis[N];
stack<int> st;
vector<vector<int> > g;
int n, m, dfstime, cmp, idx[N], low[N], id[N], in[N];

void dfs(int u){

	idx[u] = low[u] = ++dfstime;
	st.push(u);
	vis[u] = true;

	for(int i = 0; i < (int)g[u].size(); ++i) {

		int v = g[u][i];
		if(idx[v] == 0)
			dfs(v);
		if(vis[v]) low[u] = min(low[u], low[v]);
	}

	if(idx[u] == low[u]) {
		while(true){
			int v = st.top();
			st.pop();
			vis[v] = false;
			id[v] = cmp;
			if(v == u) break;
		}
		++cmp;
	}
}

void solve(){

	g.clear();
	dfstime = 0; cmp = 0;
	while(!st.empty()) st.pop();
	memset(vis, 0, sizeof vis);
	memset(idx, 0, sizeof idx);
	memset(low, 0, sizeof low);
	memset(id, 0, sizeof id);
	memset(in, 0, sizeof in);

	scanf("%d%d", &n, &m);

	g.resize(n);
	for(int i = 0, from, to; i < m; ++i) {
		scanf("%d%d", &from, &to);
		--from; --to;
		g[from].push_back(to);
	}

	for(int i = 0; i < n; ++i) {
		if(idx[i] == 0)
			dfs(i);
	}

	for(int u = 0; u < n; ++u) {
		for(int j = 0; j < (int)g[u].size(); ++j) {
			int v = g[u][j];

			if(id[u] != id[v])
				++in[id[v]];
		}
	}

	int ans = 0;
	for(int i = 0; i < cmp; ++i){
		if(in[i] == 0)
			++ans;
	}
	
	printf("%d\n", ans);

}

int main(int argc, char const *argv[]){

	//freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t-- > 0) 
		solve();

	return 0;
}