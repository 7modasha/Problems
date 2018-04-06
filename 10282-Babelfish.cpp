#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);
	// solvable with sstream

	string a;
	map<string, string> dic;
	

	while (getline(cin, a) && a != ""){

		int indx = a.find(' ');
		dic[a.substr(indx+1, 11)] = a.substr(0, indx);
	}

	while (cin >> a){

		if (dic.count(a))
			cout << dic[a] << endl;
		else
			cout << "eh" << endl;
	}

	return 0;
}
