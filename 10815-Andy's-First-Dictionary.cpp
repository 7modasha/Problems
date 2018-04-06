#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif

	string s;
	set<string> st;

	while (cin >> s){

		string tmp = "";

		FOR(0, s.size()){

			if (isalpha(s[i])){
				tmp += tolower(s[i]);
			}
			else if (tmp != ""){
				st.insert(tmp);
				tmp = "";
			}
		}

		if (tmp != "") st.insert(tmp);
		tmp = "";
	}

	for (auto i : st) cout << i << endl;

	return 0;
}
