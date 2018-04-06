#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 15;
bitset<N> prime;

void sieve(){

	prime[0] = prime[1] = 1;

	for (int i = 0; i * i < N; i++){
		if (!prime[i])
			for (int j = i * i; j < N; j += i)
				prime[j] = 1;
	}
}

int rev(int n){

	int ans = 0;

	while (n != 0) { ans = ans * 10 + n % 10; n /= 10; }
	
	return ans;
}

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	sieve();

	int n;
	while (cin >> n){

		int m = rev(n);

		if (prime[n] == 0){

			if (prime[m] == 0 && n != m)
				printf("%d is emirp.\n", n);
			else
				printf("%d is prime.\n", n);
		}
		else
			printf("%d is not prime.\n", n);
	}

	return 0;
}
