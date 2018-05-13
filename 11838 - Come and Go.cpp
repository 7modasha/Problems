#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

bool vis[N];
stack<int> st;
vector<vector<int> > g;
int n, m, dfstime, idx[N], low[N], cmp;

void dfs(int u){
	idx[u] = low[u] = ++dfstime;
	st.push(u);
	vis[u] = true;

	for(int i = 0, v; i < (int)g[u].size(); ++i) {

		v = g[u][i];
		if(idx[v] == 0) dfs(v);
		if(vis[v]) low[u] = min(low[u], low[v]);
	}

	if(idx[u] == low[u]) {
		while(true){
			int v = st.top();
			st.pop();
			vis[v] = false;
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

	g.resize(n);
	for(int i = 0, from, to, p; i < m; ++i){
		scanf("%d%d%d", &from, &to, &p);
		--from; --to;
		g[from].push_back(to);
		if(p == 2) g[to].push_back(from);
	}

	for(int i = 0; i < n; ++i)
		if(idx[i] == 0)
			dfs(i);

	if(cmp == 1)
		puts("1");
	else
		puts("0");
}

int main(int argc, char const *argv[]){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	while(scanf("%d%d", &n, &m) && n > 0)
		solve();

	return 0;
}