#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	int m, n, itmp, sum;
	string stmp;
	map<string, int> dic;

	cin >> m >> n;
	while (m--){
		cin >> stmp >> itmp;
		dic[stmp] = itmp;
	}

	while (n--){

		sum = 0;
		while (cin >> stmp && stmp != "."){
			if (dic.count(stmp)) sum += dic[stmp];
		}

		cout << sum << endl;
	}

	return 0;
}
