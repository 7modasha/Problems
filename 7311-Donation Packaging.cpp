#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

	int n;
	int a, b, c;
	int A(0), B(0), C(0);

	cin >> n;

	while (n-- > 0) {

		cin >> a >> b >> c;

		A += a; B += b; C += c;

		if (A >= 30 && B >= 30 && C >= 30) {

			int MIN = min(min(A, B), C);
			cout << MIN << endl;
			A -= MIN; B -= MIN; C -= MIN;
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}