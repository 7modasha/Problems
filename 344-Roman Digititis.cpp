#include <bits/stdc++.h>

#define ll long long

using namespace std;

int i, v, x, l, c, n;

void solve() {

	i = v = x = l = c = 0;

	for (int p = 1; p <= n; p++) {

		switch (p % 10) {
		case 1: i++; break;
		case 2: i += 2; break;
		case 3: i += 3; break;
		case 4: v++, i++; break;
		case 5: v++; break;
		case 6: v++, i++; break;
		case 7: v++, i += 2; break;
		case 8: v++, i += 3; break;
		case 9: i++, x++; break;
		}
		switch (p / 10) {
		case 1: x++; break;
		case 2: x += 2; break;
		case 3: x += 3; break;
		case 4: x++, l++; break;
		case 5: l++; break;
		case 6: l++, x++; break;
		case 7: l++, x += 2; break;
		case 8: l++, x += 3; break;
		case 9: x++, c++; break;
		case 10: c++; break;
		}
	}
}

int main() {

	while (cin >> n && n) {

		solve();
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
	}

	return 0;
}