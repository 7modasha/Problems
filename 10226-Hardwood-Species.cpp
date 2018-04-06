#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	int n, c;
	string s;
	map<string, int> trees;

	cin >> n; cin.ignore(); cin.ignore();
	while (n--){

		c = 0; trees.clear();

		while (getline(cin, s) && s != ""){
			trees[s]++; c++;
		}

		for (map<string, int>::iterator it = trees.begin(); it != trees.end(); it++){
			cout << it->first << ' ' << fixed << setprecision(4) <<
				100.0 * it->second / c << endl;
		}

		if (n) cout << endl;
	}

	return 0;
}
