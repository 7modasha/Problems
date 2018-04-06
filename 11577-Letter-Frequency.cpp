#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	int t;
	string s;
	map<char, int> m;
	
	cin >> t; cin.ignore();
	while (getline(cin, s) && t--){
	
		m.clear();
		int mx = 0;
	
		for (auto i : s) { 
			i = tolower(i);
			if (isalpha(i)) m[i]++; 
			mx = max(mx, m[i]); 
		}
	
		for (auto i : m) {
	
			if (i.second == mx) cout << i.first;
		}

		cout << endl;
	}

	return 0;
}
