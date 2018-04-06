#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 1, oo = 1e9;
int n, m;
bool vis[N];
pair<int, int> cost[N];

vector<vector<pair<int, int> > > g;

priority_queue<pair<ll, int> > q;

void Dijkstra(int src) {

	while (!q.empty()) q.pop();
	fill(cost, cost + N, make_pair(oo, 0));
	memset(vis, false, sizeof vis);

	q.push(make_pair(0, src));
	cost[src].first = 0;
	cost[src].second = 0;

	while (!q.empty()) {

		int v = q.top().second;
		int c = -q.top().first;

		q.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for (int i = 0; i < g[v].size(); i++) {

			int u = g[v][i].first;

			if (c + g[v][i].second < cost[u].first) {

				cost[u].first = c + g[v][i].second;
				cost[u].second = u;

				q.push(make_pair(-cost[u].first, u));
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	g.resize(n);

	for (int i = 0, from, to, cost; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);

		g[from].push_back(make_pair(to, cost));
		g[to].push_back(make_pair(from, cost));
	}

	int k;
	scanf("%d", &k);

	Dijkstra(0);

	sort(cost, cost + n);

	printf("%d\n", cost[k].second);

	return 0;
}