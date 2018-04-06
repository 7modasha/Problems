#include <bits/stdc++.h>
using namespace std;

int main() {

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	vector<lli> d;
	lli t, n, m, mxN, mxD;

	cin >> t;

	while (t--){

		mxN = 1; mxD = 1;

		cin >> n >> m;

		for (lli i = n; i <= m; i++){

			d.clear();

			for (lli j = 1; j * j <= i; j++){
				if (i % j == 0) {
					d.push_back(j);

					if (j * j != i)
						d.push_back(i / j);
				}
			}

			if (mxD < d.size()){
				mxD = d.size(); mxN = i;
			}
		}

		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", n, m, mxN, mxD);
	}
	
	return 0;
}
