#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t;
	string s;

	cin >> t;

	for (int i = 0; t--; i++){

		cin >> s;

		sort(all(s));

		do{
			cout << s << endl;

		} while (next_permutation(all(s)));

		cout << endl;
	}

	return 0;
}
