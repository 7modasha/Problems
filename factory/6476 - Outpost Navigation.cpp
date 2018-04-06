#include <bits/stdc++.h>
using namespace std;

//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4487

map<string, int> id;
vector<pair<int, bool> > op;
vector<vector<pair<int, int> > > roads;

int n, r, secAmmo;

int vis[103], z[103], ammo[103];
priority_queue<pair<int, int> > q;

void Dij(int src, int initAmmo){
	while(!q.empty()) q.pop();
	fill(z, z + n, 1000000000);
	memset(vis, 0, sizeof vis);
	memset(ammo, 0, sizeof ammo);

	ammo[src] = initAmmo;
	op[src].first = 0;

	q.push(make_pair(0, src));

	while(!q.empty()){
		int v = q.top().second;
		int vz = -q.top().first;
		q.pop();

		if(vis[v]) continue;
		vis[v] = true;

		for (int i = 0; i < (int)roads[v].size(); ++i){
			int u = roads[v][i].first;
			int uz = roads[v][i].second;

			if(vz + uz < z[u] && ammo[v] >= uz){
				ammo[u] = ammo[v] - uz + op[u].first;
				z[u] = vz + uz;
				q.push(make_pair(-z[u], u));
			}
		}
	}
}

void solve(){

	id.clear();
	op.clear();
	roads.clear();
	secAmmo = -1;

	scanf("%d%d", &n, &r);

	int Ammo;
	char name[10], supplies[5];

	for (int i = 0; i < n; ++i){
		scanf("%s %d %s", name, &Ammo, supplies);

		id[name] = i;
		op.push_back(make_pair(Ammo, strcmp(supplies, "yes") == 0));

		if(Ammo > 0)
			secAmmo = i;
	}

	roads.resize(n);

	int zombies;
	char from[10], to[10];

	for (int i = 0; i < r; ++i){
		scanf("%s %s %d", from, to, &zombies);

		roads[id[from]].push_back(make_pair(id[to], zombies));
		roads[id[to]].push_back(make_pair(id[from], zombies));
	}

	if(op[0].second){
		puts("0");
		return;
	}

	Dij(0, op[0].first);
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		if(op[i].second && z[i] < ans)
			ans = z[i];
	}

	if(secAmmo == -1 || z[secAmmo] == 1000000000){

		if(ans == 1000000000)
			puts("No safe path");
		else
			printf("%d\n", ans);
		
		return;
	}

	int zombiesToSec = z[secAmmo];
	
	Dij(secAmmo, ammo[secAmmo]);

	for(int i = 0; i < n; ++i){
		if(op[i].second && z[i]+zombiesToSec < ans)
			ans = z[i]+zombiesToSec;
	}

	if(ans == 1000000000)
		puts("No safe path");
	else
		printf("%d\n", ans);
}

int main() {

	freopen("in.txt", "r", stdin);
	
	int t;
	scanf("%d", &t);
	while(t-- > 0) solve();
	
	return 0;
}