#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 15;
bitset<N> prime;

void sieve(){

	prime[0] = prime[1] = 1;

	for (int i = 2; i * i < N; i++){
		if (!prime[i])
			for (int j = i * i; j < N; j += i)
				prime[j] = 1;
	}
}

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	sieve();

	int n;

	while (scanf("%d", &n) != EOF){

		if (n < 8) { printf("Impossible.\n"); continue; }

		if (n % 2 == 0){
			printf("2 2 "); n -= 4;
		}
		else{
			printf("2 3 "); n -= 5;
		}

		int l = 1, r = n - 1;

		while (l <= r){

			if (!prime[l] && !prime[r]) break;

			l++; r--;
		}

		printf("%d %d\n", l, r);
	}

	return 0;
}
