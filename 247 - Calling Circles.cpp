#include <bits/stdc++.h>

using namespace std;

const int N = 100;

bool vis[N];
stack<int> st;
vector<string> r;
map<string, int> mp;
vector<vector<int> > g;
int n, m, dfstime, idx[N], low[N];

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

			printf("%s", r[v].c_str());
			if(v == u) break;
			printf(", ");
		}
		puts("");
	}
}

void solve(){
	g.clear();
	r.clear();
	mp.clear();
	dfstime = 0;
	while(!st.empty()) st.pop();
	memset(vis, 0, sizeof vis);
	memset(idx, 0, sizeof idx);
	memset(low, 0, sizeof low);

	g.resize(n);
	r.resize(n);
	char from[30], to[30];
	for(int i = 0, id = 0, f, t; i < m; ++i) {
		scanf("%s%s", from, to);
		
		if(mp.count(from) == 0){
			r[id] = from;
			mp[from] = id++;
		}
		if(mp.count(to) == 0){
			r[id] = to;
			mp[to] = id++;
		}

		g[mp[from]].push_back(mp[to]);
	}

	for(int i = 0; i < n; ++i)
		if(idx[i] == 0)
			dfs(i);
}

int main(int argc, char const *argv[]){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t = 1 , c = 0;
	while(scanf("%d%d", &n, &m) && n > 0){
		if(c++ > 0)puts("");
		printf("Calling circles for data set %d:\n", t++);
		solve();
	}

	return 0;
}