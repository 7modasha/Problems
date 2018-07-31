#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

vector<vector<int> > g;
vector<pair<int, int> > bridges;
int n, m, dfstime, idx[N], low[N];

void DFS(int u, int p) {
	idx[u] = low[u] = ++dfstime;
	for(int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if(idx[v] == 0) {
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > idx[u])
				bridges.push_back({min(u, v), max(v, u)});	
		}
		else if(v != p)
			low[u] = min(low[u], idx[v]);
	}
}

void solve() {

	g.clear();
	dfstime = 0;
	bridges.clear();
	memset(idx, 0, sizeof idx);
	memset(low, 0, sizeof low);

	g.resize(n);
	for(int i = 0, from, to; i < m; ++i){
		scanf("%d%d", &from, &to);
		g[from].push_back(to);
		g[to].push_back(from);
	}

	for(int i = 0; i < n; ++i){
		if(idx[i] == 0){
			DFS(i, -1);
		}
	}

	sort(bridges.begin(), bridges.end());
	if(bridges.size() == 0)
		printf("0");
	else
		printf("%d ", (int)bridges.size());

	for(int i = 0; i < (int)bridges.size(); ++i){
		if(i > 0) printf(" ");
		printf("%d %d", bridges[i].first, bridges[i].second);
	}
}

int main(int argc, char const *argv[]){

	//freopen("in.txt", "r", stdin);

	int t = 0;
	while(scanf("%d%d", &n, &m) && n){
		solve();
		puts("");
	}
	
	return 0;
}