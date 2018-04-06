#include <bits/stdc++.h>
using namespace std;

bool comp(char a, char b){

	return tolower(a) == tolower(b) ? a < b : tolower(a) < tolower(b);
}

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	int t;
	string s;

	cin >> t;
	while (t--){

		cin >> s;
		sort(all(s), comp);

		do{
			cout << s << endl;
		} while (next_permutation(all(s), comp));
	}

	return 0;
}
