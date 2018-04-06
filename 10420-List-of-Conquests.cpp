#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	int t;
	string s;
	map<string, set<string>> c;

	cin >> t; cin.ignore();
	while (t--){

		getline(cin, s);

		int i = s.find(' ');
		c[s.substr(0, i)].insert(s.substr(i + 1));
	}

	for (auto it = c.begin(); it != c.end(); it++){

		cout << it->first << ' ' << it->second.size() << endl;
	}
	
	return 0;
}
