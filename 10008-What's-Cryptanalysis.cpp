#include <bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){

	if (a.second != b.second)
		return a.second > b.second;
	
	return a.first < b.first;
}

int main(){

	freopen("in.txt", "r", stdin);

	map<char, int> let;
	string s;
	int n;

	cin >> n; cin.ignore();
	while (getline(cin, s) && n--){

		for (int i = 0; i < s.length(); i++){
			if (isalpha(s[i])) let[toupper(s[i])]++;
		}
	}

	vector<pair<char, int>> rdr;

	for	(auto it : let)
		rdr.push_back(make_pair(it.first, it.second));
	
	sort(rdr.begin(), rdr.end(), comp);

	for (int i = 0; i < rdr.size(); i++)
		cout << rdr[i].first << ' ' << rdr[i].second << endl;

	return 0;
}
