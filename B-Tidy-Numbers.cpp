#include <bits/stdc++.h>
using namespace std;

vector<ll> sol;
void trY(ll n, int indx){

	if (indx == 18){

		sol.push_back(n); return;
	}

	int mod = n % 10;
	for (int i = mod; i <= 9; i++)
		trY(n * 10 + i, indx + 1);
}

int main(){

#ifdef _DEBUG
	freopen("B-large-practice.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	trY(0, 0);

	int t;
	ll n;

	scanf("%d", &t);

	for (int i = 1; i <= t; i++){

		scanf("%lld", &n);

		printf("Case #%d: %lld\n", i, sol[upper_bound(all(sol), n) - sol.begin() - 1]);

	}

	return 0;
}
