#include <bits/stdc++.h>

using namespace std;

const int N = 10100;

int n, dp[N][32][32];

pair<int, int> d[N];

int calc(int i, int b, int t){

	if(i == n) return 0;

	int &ret = dp[i][b][t];
	if(ret != -1) return ret;

	if(b == 0 && t == 0){
		
		int r1 = d[i].first + 2 * d[i].second + calc(i+1, 0, 0);
		int r2 = 3 + 2 * d[i].second + calc(i+1, 0, 0);
		int r3 = 6 + calc(i+1, 0, 0);
		int r4 = 18 + 2 * d[i].second + calc(i+1, 6, 0);
		int r5 = 36 + calc(i+1, 6, 6);
		int r6 = 45 + 2 * d[i].second + calc(i+1, 29, 0);
		int r7 = 90 + calc(i+1, 29, 29);

		ret = min(r1, min(r2, min(r3, min(r4, min(r5, min(r6,r7))))));

	} else if(t == 0){

		int r11 = 2 * d[i].second + calc(i+1, b-1, 0);
		int r22 = 6 + calc(i+1, b-1, 0);
		int r33 = 36 + calc(i+1, max(b-1, 6), 6);
		int r44 = 90 + calc(i+1, max(b-1, 29), 29);

		ret = min(r11, min(r22, min(r33, r44)));

	} else {

		ret = calc(i+1, b-1, t-1);
	}

	return ret;
}

void solve(){

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d %d", &d[i].first, &d[i].second);

	memset(dp, -1, sizeof dp);

	printf("%d\n", calc(0, 0, 0));
}

int main(int argc, char const *argv[]){

	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t-- > 0) solve();
	
	return 0;
}