#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

	int n, north, south, west, east, top, temp;
	string s;

	while (cin >> n && n) {

		north = 2, south = 5, west = 3, east = 4, top = 1;

		for (int i = 0; i < n; i++) {
			cin >> s;

			if (s == "north") {
				temp = 7 - north;
				north = top;
				south = 7 - top;
				top = temp;
			}
			else if (s == "south") {
				temp = 7 - south;
				south = top;
				north = 7 - top;
				top = temp;
			}
			else if (s == "west") {
				temp = 7 - west;
				west = top;
				east = 7 - top;
				top = temp;
			}
			else if (s == "east") {
				temp = 7 - east;
				east = top;
				west = 7 - top;
				top = temp;
			}
		}

		cout << top << endl;
	}
	return 0;
}