#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;

int n, m, dp[1001][1001];

int calc(int i, int j) {
	
	if (i >= n || j >= m) return 0;

	if (i == n - 1 && j == m - 1) return 1;

	int &ret = dp[i][j];
	if (ret != -1) return ret;

	return ret = calc(i + 1, j) + calc(i, j + 1);
}


int main() {

	int t, tmp2, c = 0;
	string tmp1;

	scanf("%d", &t);

	while (t-- > 0) {

		memset(dp, -1, sizeof dp);

		if (c++ > 0) cout << endl;

		cin >> n >> m;
		cin.ignore();

		for (int i = 0; i < n; ++i) {
			getline(cin, tmp1);
			stringstream ss(tmp1);

			ss >> tmp2;
			while (ss >> tmp2) {
				dp[i][tmp2 - 1] = 0;
			}
		}

		cout << calc(0, 0) << endl;
	}	

	return 0;
}
