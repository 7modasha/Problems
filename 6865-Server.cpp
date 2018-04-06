#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	vector<lli> a;
	lli n, t, c;

	while (cin >> n >> t){

		a.clear(); a.resize(n); c = 0;

		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++){
			if (t - a[i] >= 0){
				t -= a[i]; c++;
			}
			else break;
		}

		cout << c << endl;
	}

	return 0;
}
