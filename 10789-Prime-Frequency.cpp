#include <bits/stdc++.h>
using namespace std;

bool primes[6001];

void sieve(){

	memset(primes, true, sizeof primes);

	primes[0] = 0; primes[1] = 0;

	for (int i = 2; i * i <= 6000; i++){

		if (primes[i])
			for (int j = i + i; j <= 6000; j += i)
				primes[j] = false;
	}

}


int main() {

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	sieve();
	map<char, int> m;

	int T;
	string s, ans;

	cin >> T;

	for (int i = 1; T--; i++){

		m.clear();
		ans = "";

		cin >> s;

		for (int j = 0; j < s.size(); j++){
			m[s[j]]++;
		}

		for (auto it : m){

			if (primes[it.second])
				ans += it.first;
		}

		printf("Case %d: %s\n", i, ans.size() ? ans.c_str() : "empty");
	}

	return 0;
}
