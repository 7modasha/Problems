#include <iostream>

using namespace std;

int main() {

	int n, a[51], sum;

	for (int i = 1; cin >> n && n; ++i) {

		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i]; sum += a[i];
		}

		sum /= n;

		int ans = 0;
		for (int i = 0; i < n; ++i) {

			if (sum - a[i] > 0) ans += (sum - a[i]);

		}

		cout << "Set #" << i << endl;
		cout << "The minimum number of moves is " << ans << "." << endl << endl;
	}
	

	return 0;
}
