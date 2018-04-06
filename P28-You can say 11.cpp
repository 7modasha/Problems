#include <bits/stdc++.h>

#define ll long long

using namespace std;

string trim(string s) {

	string ans = "";

	for each (char i in s){
		
		if (i != ' ') ans += i;
	}

	return ans;
}

int main() {
	
	string s;

	while (cin >> s && s != "0") {

		s = trim(s);

		int sum = 0, sign = 1;

		for (int i = 0; i < s.length(); i++, sign = -sign) {

			sum += sign * (s[i] - '0');
		}

		if (sum % 11 == 0)
			cout << s << " is a multiple of 11." << endl;
		else
			cout << s << " is not a multiple of 11." << endl;

	}

	return 0;
}