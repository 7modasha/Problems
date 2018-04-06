#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("in.txt", "r", stdin);

	int t, n, d, itmp;
	string stmp;
	map<string, int> sub;

	cin >> t;
	for (int i = 1; i <= t; i++){

		sub.clear();

		cin >> n;
		while (n--){
			cin >> stmp >> itmp;
			sub[stmp] = itmp;
		}

		cin >> d >> stmp;

		if (sub[stmp] <= d && sub[stmp] > 0)
			printf("Case %d: Yesss\n", i);
		else if (sub[stmp] > d && sub[stmp] <= d+5)
			printf("Case %d: Late\n", i);
		else
			printf("Case %d: Do your own homework!\n", i);

	}

	return 0;
}
