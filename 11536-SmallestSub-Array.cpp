#include <bits/stdc++.h>
using namespace std;

#define N 1000100
int x[N], fr[103];
int k, m, n, t;

void fill(){

	x[0] = 1; x[1] = 2; x[2] = 3;

	for (int i = 3; i < n; i++) 
		x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % m + 1;

	for (int i = 0; i < 103; i++) fr[i] = 0;
}

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif


	scanf("%d", &t);

	for (int i = 1; i <= t; i++){

		scanf("%d%d%d", &n, &m, &k);

		fill();

		int l = 0, r = 0, res = N, c = 0;

		while (r < n){

			if (x[r] <= k && fr[x[r]]++ == 0) c++;


			while (c == k){

				res = min(res, r - l + 1);

				if (x[l] <= k && fr[x[l]]-- == 1) c--;

				l++;
			}

			r++;
		}

		if (res == N)
			printf("Case %d: sequence nai\n", i);
		else
			printf("Case %d: %d\n", i, res);

	}

	return 0;
}
