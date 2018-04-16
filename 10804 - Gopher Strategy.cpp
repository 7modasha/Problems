#include <bits/stdc++.h>
#define EPS -1e9

using namespace std;

struct Point{
	double x, y;

} go[55], hole[55];

double ds[55][55], md;
int match[55], vis[55], id = 1, n, m, k;

double dist(Point &a, Point &b){
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

double init(){
	double mx = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ds[i][j] = dist(go[i], hole[j]);
			mx = max(mx, ds[i][j]);
		}
	}

	return mx;
}

bool findmatch(int v){
	vis[v] = id;

	for (int u = 0; u < m; ++u){

		if(ds[v][u]+EPS <= md+EPS && (match[u] == -1 || (vis[match[u]] != id && findmatch(match[u])))){

			match[u] = v;
			return true;
		}
	}
	return false;
}

int maxMatching(){
	id = 1;
	memset(vis, 0, sizeof vis);
	memset(match, -1, sizeof match);

	int res = 0;
	for(int i = 0; i < n; ++i){
		if(findmatch(i)) ++res;
		++id;
	}

	return res;
}

int main(int argc, char const *argv[]){

	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	for(int T = 1; T <= t; ++T){

		scanf("%d%d%d", &n, &m, &k);

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


		double ans = 0;
		double l = 0, r = init();

		for(int i = 0; i < 101; ++i){

			md = (l+r)/2.0;

			int res = maxMatching();

			if(res >= n-k) ans = r = md;
			else l = md;
		}

		md = ans;
		int res = maxMatching();

		printf("Case #%d:\n", T);

		if(res >= n-k){
			printf("%.3lf\n\n", ans);
		} else {
			puts("Too bad.\n");
		}
	}

	return 0;
}