#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("in.txt", "r", stdin);

	char tmp;
	map<char, int> m;
	vector<char> a;

	while (cin >> tmp){

		if (!m.count(tmp))
			a.push_back(tmp);

		m[tmp]++;
	}

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ' << m[a[i]] << endl;

	return 0;
}
