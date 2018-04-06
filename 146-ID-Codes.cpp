#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	string s;

	while (cin >> s && s != "#"){

		if (next_permutation(all(s)))
			cout << s << endl;
		else
			cout << "No Successor\n";
	}

	return 0;
}
