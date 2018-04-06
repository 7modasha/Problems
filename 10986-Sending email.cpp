#include <bits/stdc++.h>

#define ll long long

using namespace std;

int const N = 1e5 + 1;
ll oo = 1e15, cost[N];
int n, m;
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int> > q;

void Dijkstra(int src) {

	while (!q.empty()) q.pop();
	fill(cost, cost + N, oo);
	memset(vis, false, sizeof vis);

	q.push(make_pair(0, src));
	cost[src] = 0;

	while (!q.empty()) {
		int v = q.top().second;
		int c = -q.top().first;
		q.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v][i].first;
			if (c + g[v][i].second < cost[u]) {

				cost[u] = c + g[v][i].second;
				q.push(make_pair(-cost[u], u));
			}
		}
	}
}

int main() {

	int t;
	scanf("%d", &t);

	for (int i = 1; t-- > 0; i++) {

		int a, b;
		scanf("%d %d %d %d", &n, &m, &a, &b);

		g.clear(); g.resize(n);

		for (int i = 0, from, to, cost; i < m; i++) {
			scanf("%d %d %d", &from, &to, &cost);

			g[from].push_back(make_pair(to, cost));
			g[to].push_back(make_pair(from, cost));
		}
		
		Dijkstra(a);

		if (cost[b] == oo)
			printf("Case #%d: unreachable\n", i);
		else
			printf("Case #%d: %d\n", i, cost[b]);
	}

	return 0;
}
