#include <bits/stdc++.h>
using namespace std;

const int N = 1299709 + 15;
bitset<N> prime;

void sieve(){

	prime[0] = prime[1] = 1;

	for (int i = 0; i * i < N; i++){
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

	int ans = 0, n;

	
	while (cin >> n && n){

		int l = n, r = n;

		while (true){

			if (l >= 0 && prime[l--] == 1) ans++; else break;
		}

		while (true){

			if (prime[r++] == 1) ans++; else break;
		}

		cout << (r - l) - 2 << endl;
	}

	return 0;
}
