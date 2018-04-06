#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

pair<int, int> a[101];

int dp[101][40004], m, n;

int calc(int i, int p) {
	
	if (i == n) {

		if (p <= m || p > 2000 && p <= m + 200)
			return 0;
		else
			return -40004;
	}

	int &ret = dp[i][p];
	if (ret != -1) return ret;

	int r = -1;
	if (p + a[i].first <= m + 200)
		r = calc(i + 1, p + a[i].first) + a[i].second;

	ret = calc(i + 1, p);

	if (ret >= 0 || r >= 0)
		ret = max(ret, r);

	return ret;
}

int main() {

	while (scanf("%d%d", &m, &n) != EOF) {

		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i].first, &a[i].second);

		int res = calc(0, 0);

		printf("%d\n", res);
	}

	return 0;
}
