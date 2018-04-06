#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int dx[] = { 1,0,-1,0 }; 
int dy[] = { 0,1,0,-1 };

int dp[101][101], r, c, g[101][101];

 int calc(int x, int y) {

	 int &ret = dp[x][y];
	 if (ret != -1)
		 return ret;

	 ret = 1;

	 for (int i = 0; i < 4; ++i) {

		 int nx = x + dx[i];
		 int ny = y + dy[i];

		 if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[x][y] > g[nx][ny])
			ret = max(ret, 1 + calc(nx, ny));
	 }	
	 return ret;
}

int main() {

	int t;
	string s;

	scanf("%d", &t);
	while (t-- > 0) {

		memset(dp, -1, sizeof dp);

		cin >> s;

		scanf("%d%d", &r, &c);

		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				scanf("%d", &g[i][j]);

		int res = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				res = max(res, calc(i, j));
			}
		}

		printf("%s: %d\n", s.c_str(), res);
	}

	return 0;
}
