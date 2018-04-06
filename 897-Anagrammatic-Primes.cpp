#include <bits/stdc++.h>
using namespace std;

int an[] = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 
71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991 };

int main() {


#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int ans, n;

	while (cin >> n && n){

		ans = 22;

		for (int i = 21; i >= 0 && an[i] > n; i--, ans--);

		int d = 1;

		while (n != 0){
			n /= 10; d *= 10;
		}

		printf("%d\n", an[ans] < d && ans < 22 ? an[ans] : 0);
	}

	return 0;
}
