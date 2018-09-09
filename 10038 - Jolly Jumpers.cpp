#include <bits/stdc++.h>
using namespace std;

const int N = 30000;

int n, a[N], diff[N];

string chk(){
	if(n == 1) return "Jolly";

	for(int i = 0; i+1 < n; ++i)
		diff[abs(a[i]-a[i+1])] = 1;


	for(int i = 1; i <= n-1; ++i)
		if(diff[i] == 0) return "Not jolly";

	return "Jolly";
}

int main(){
 
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	while(cin >> n){
		memset(diff, 0, sizeof diff);

		for(int i = 0; i < n; ++i)
			cin >> a[i];
		cout << chk() << endl;
	}
	
	return 0;
}