#include <bits/stdc++.h>

using namespace std;

int vol[31], match[36], vis[31], ti, vo, d, id;
vector<vector<int> > g;

bool findmatch(int v){
	vis[v] = id;

	for (int i = 0; i < (int)g[v].size(); ++i){

		int s = g[v][i]*d, e = g[v][i]*d + d;

		for(int j = s; j < e; ++j){

			if(match[j] == -1 || (vis[match[j]] != id && findmatch(match[j]))){

				match[j] = v;
				return true;
			}
		}
	}
	return false;
}

int insert(int v, string s){

	if(s == "XS")
		g[v].push_back(0);
	else if(s == "S")
		g[v].push_back(1);
	else if(s == "M")
		g[v].push_back(2);
	else if(s == "L")
		g[v].push_back(3);
	else if(s == "XL")
		g[v].push_back(4);
	else
		g[v].push_back(5);
}

int main(int argc, char const *argv[]){

	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t-- > 0){

		scanf("%d%d", &ti, &vo);

		d = ti / 6;

		g.clear();
		g.resize(vo);
		char a[5], b[5];

		for(int i = 0; i < vo; ++i){
			scanf("%s%s", a, b);

			insert(i, a);
			insert(i, b);
		}

		id = 1;
		int res = 0;
		memset(vis, 0, sizeof vis);
		memset(match, -1, sizeof match);

		for(int i = 0; i < vo; ++i){
			if(findmatch(i)) ++res;
			++id;
		}

		if(res == vo)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}