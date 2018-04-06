#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

	int tmp;
	string s;
	stringstream ss;
	vector<int> a, b;

	while (getline(cin, s)) {

		a.clear(); b.clear();

		A set
		ss << s;
		while (ss >> tmp) a.push_back(tmp);

		getline(cin, s); 
		ss.str(string()); ss.clear();

		B set
		ss << s;
		while (ss >> tmp) b.push_back(tmp);

		int ac = 0, bc = 0;

		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++)
				if (a[i] == b[j]) { ac++; break; }

		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < a.size(); j++)
				if (b[i] == a[j]) { bc++; break; }

		if (a.size() == ac && a.size() < b.size())
			puts("A is a proper subset of B");
		else if (b.size() == bc && b.size() < a.size())
			puts("B is a proper subset of A");
		else if (a.size() == b.size() && ac == a.size() && bc == b.size())
			puts("A equals B");
		else if (ac == 0 && bc == 0)
			puts("A and B are disjoint");
		else
			puts("I'm confused!");
	}

	return 0;
}