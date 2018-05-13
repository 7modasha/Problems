#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, q;
char a[N], b[N], c[N];

int ar[10][10][N];
vector<int> ans[10][10];

int solve(){
	
	scanf("%d%d", &n, &q);
	scanf("%s%s%s", a, b, c);

	for(int i = 0, r1, r2, r3, r4; i < n; ++i){

		r1 = a[i] - '0'; r2 = b[i] - '0'; 
		r3 = c[i] - '0'; 

		if(i > 0) {
			//r4 = ;

			for(int j = 0; j < 10; ++j){
				for(int k = 0; k < 10; ++k){

					if(j == r1 && k == r2 && r3 != r4){

						ar[j][k][i] = 1;

					} else {
						if(ar[j][k][i-1] > 0) ar[j][k][i] = ar[j][k][i-1] + 1;
					}
				}
			}
			

		} else {
			ar[r1][r2][i] = 1;
		}
	}


	cout << ar[3][8][2] << ' ' << ar[3][8][4] << endl;
}

int main(int argc, char const *argv[]){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	//solve();

	int n, m;
	cin >> n >> m;
	cout << n << " " << m << endl;
	
	return 0;
}