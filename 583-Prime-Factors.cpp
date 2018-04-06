#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bitset<N> bs;
vector<int> p;
vector<int> sol;

void sieve() {

	bs[0] = bs[1] = 1;

	for (int i = 2; i * i < N; i++)
		if (bs[i] == 0)
		for (int j = i * i; j < N; j += i)
			bs[j] = 1;

	for (int i = 0; i < N; i++)
		if (bs[i] == 0)
			p.push_back(i);
}

void primeFact(lli n) {

	sol.clear();

	int freq;
	for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
		freq = 0;

		while (n % p[i] == 0) {
			++freq;
			n /= p[i];
		}

		while (freq != 0){
			sol.push_back(p[i]); freq--;
		}
	}

	if (n != 1) sol.push_back(n);
}

int main() {


#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	sieve();

	lli n;

	while (cin >> n && n){

		primeFact(n < 0 ? -1 * n : n);

		cout << n << " = ";

		for (int i = 0; i < sol.size(); i++){

			if (i > 0) cout << " x ";

			if (n < 0 && i == 0) cout << -1 << " x ";

			cout << sol[i];
		}

		cout << endl;
	}

	return 0;
}
