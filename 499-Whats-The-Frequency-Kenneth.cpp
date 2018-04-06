#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	string s;
	map<char, int> m;

	while (getline(cin, s)){

		m.clear();
		int mx = 0;

		for (auto i : s) { if (isalpha(i)) m[i]++; mx = max(mx, m[i]); }

		for (auto i : m) {

			if (i.second == mx) cout << i.first;
		}

		cout << ' ' << mx << endl;
	}

	return 0;
}
