#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	string a, b;

	int c = 1;
	while (cin >> a >> b && a != "END" && b != "END"){

		if (a.size() != b.size()){
			cout << "Case " << c << ':' << " different\n";
			c++;
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		printf("Case %d: %s\n", c, (a == b) ? "same" : "different");
		c++;
	}

	return 0;
}
