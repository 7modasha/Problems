#include <bits/stdc++.h>
using namespace std;

int main() {


#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif


	int c = 0, n, m, s1, s2;
	vector<int> a;

	while (cin >> n){

		a.clear(); a.resize(n);

		FOR(0, n) cin >> a[i];

		sort(all(a));

		cin >> m;

		s1 = m / 2;
		s2 = m % 2 != 0 ? s1 + 1 : s1;

		while (0 < s1 && s2 < m){

			if (binary_search(all(a), s1)
				&& binary_search(all(a), s2)){
				printf("Peter should buy books whose prices are %d and %d.\n\n", s1, s2);
				break;
			}
			s1--; s2++;
		}
	}

	return 0;
}
