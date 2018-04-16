#include <bits/stdc++.h>
#define EPS -1e9

using namespace std;

struct Point{
	double x, y;

} go[111], hole[111];

int match[111], vis[111], id = 1, n, m, s, vel;

double dist(Point &a, Point &b){
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

bool findmatch(int v){
	vis[v] = id;

	for (int u = 0; u < m; ++u){

		bool can = (dist(go[v], hole[u])/vel)+EPS <= double(s)+EPS;

		if(can && (match[u] == -1 || (vis[match[u]] != id && findmatch(match[u])))){
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[]){

	//freopen("in.txt", "r", stdin);

	while(scanf("%d%d%d%d", &n, &m, &s, &vel) != EOF && vel > 0){

		for(int i = 0; i < n; ++i){
			double x, y;
			scanf("%lf%lf", &x, &y);
			go[i].x = x;
			go[i].y = y;
		}

		for(int i = 0; i < m; ++i){
			double x, y;
			scanf("%lf%lf", &x, &y);
			hole[i].x = x;
			hole[i].y = y;
		}

		memset(match, -1, sizeof match);
		memset(vis, 0, sizeof vis);

		int res = 0;
		for(int i = 0; i < n; ++i){
			if(findmatch(i)) ++res;
			++id;
		}
		printf("%d\n", n - res);
	}

	return 0;
}