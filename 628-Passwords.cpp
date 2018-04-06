#include <bits/stdc++.h>

#define ll long long

using namespace std;

int numOfWords;
string rule;
string output[500], words[500];

void rec(int p) {

	if (p == rule.size()) {

		for (int i = 0; i < p; i++)
			cout << output[i];
		cout << endl;

		return;
	}

	if (rule[p] == '#') {

		for (int i = 0; i < numOfWords; i++) {
			output[p] = words[i]; rec(p + 1);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			output[p] = (i + '0'); rec(p + 1);
		}
	}
	
}

int main() {

	while (cin >> numOfWords) {

		for (int i = 0; i < numOfWords; i++) cin >> words[i];

		int numOfRules;
		cin >> numOfRules;
		cout << "--" << endl;
		while (numOfRules-- > 0) {
			cin >> rule;
			rec(0);
		}
	}
	
	return 0;
}