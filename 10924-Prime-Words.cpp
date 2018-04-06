#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 15;
bitset<N> prime;

void sieve(){

	prime[0] = 1;

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

	string s;
	int sum;

	while (cin >> s){

		sum = 0;

		for (int i = 0; i < s.size(); i++){

			sum += isupper(s[i]) ? s[i] - 'A' + 27 : s[i] - 'a' + 1;
		}

		if (!prime[sum])
			cout << "It is a prime word.\n";
		else
			cout << "It is not a prime word.\n";
	}


	return 0;
}
