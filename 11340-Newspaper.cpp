#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	int n, k, m, sum, itmp;
	string line;
	char ctmp;
	map<char, int> t;

	cin >> n;

	while (n--){

		sum = 0; t.clear();

		cin >> k;
		while (k--){
			cin >> ctmp >> itmp;
			t[ctmp] = itmp;
		}

		cin >> m; cin.ignore();
		while (m--){

			getline(cin, line);
			for (int i = 0; i < line.size(); i++) sum += t[line[i]];
		}

		printf("%.2f$\n", 1.0 * sum / 100);

	}

	return 0;
}
