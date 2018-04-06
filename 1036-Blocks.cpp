#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

	int t, n, minArea;

	scanf("%d", &t);
	
	while (t-- > 0) {

		scanf("%d", &n);
		minArea = 1 << 24;

		for (int l = 1; l < n; l++) {
			for (int w = 1; w < n; w++) {
				for (int h = 1; h < n; h++)
					if (l * w * h == n)
						minArea = min(minArea, 2 * (h * w + l * w + l * h));
			}
		}

		printf("%d\n", minArea);
	}

	return 0;
}
