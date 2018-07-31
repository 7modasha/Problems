#include <bits/stdc++.h>

using namespace std;

const int N = 30;


bool vis[N];
char rev[N];
stack<int> st;
vector<vector<int> > g;
vector<int> comps[N];
int n, dfstime, idx[N], low[N], cmp, mp[N], id;

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
			comps[cmp].push_back(rev[v]);
			if(v == u) break;
		}
		sort(comps[cmp].begin(), comps[cmp].end());
		++cmp;
	}
}

void solve(){

	g.clear();
	for(int i = 0; i < N; ++i) comps[i].clear();
	dfstime = 0; cmp = 0; id = 0;
	while(!st.empty()) st.pop();
	memset(vis, 0, sizeof vis);
	memset(idx, 0, sizeof idx);
	memset(low, 0, sizeof low);
	memset(mp, -1, sizeof mp);


	g.resize(N);
	for(int i = 0; i < n; ++i){
		char ch;
		vector<int> cc;
		for(int j = 0; j < 5; ++j){
			scanf(" %c", &ch);
			if(mp[ch - 'A'] == -1){
				rev[id] = ch;
				mp[ch - 'A'] = id++;
			}

			cc.push_back(mp[ch - 'A']);
		}
		scanf(" %c", &ch);
		if(mp[ch - 'A'] == -1){
			rev[id] = ch;
			mp[ch - 'A'] = id++;
		}
		for(int j = 0; j < 5; ++j)
			g[mp[ch - 'A']].push_back(cc[j]);
	}

	for(int i = 0; i < id; ++i)
		if(idx[i] == 0)
			dfs(i);

	sort(comps, comps + cmp);
	for(int i = 0; i < cmp; ++i){
		for(int j = 0; j < (int)comps[i].size(); ++j){
			if(j > 0) printf(" ");
			printf("%c", comps[i][j]);
		}
		puts("");
	}
}

int main(int argc, char const *argv[]){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int cnt = 0;
	while(scanf("%d%d", &n) && n > 0){
		if(cnt++ > 0) puts("");
		solve();
	}

	return 0;
}