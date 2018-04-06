#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	int n, m, c = 0;
	set<lli> a;
	lli tmp;

	while (cin >> n >> m && n != 0 && m != 0){

		c = 0;

		a.clear();

		FOR(i, n) {
			cin >> tmp; a.insert(tmp);
		}

		FOR(i, m) {

			cin >> tmp;

			if (a.find(tmp) != a.end()) c++;
		}

		cout << c << endl;
	}

	return 0;
}
