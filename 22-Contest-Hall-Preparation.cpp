#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int board[101][101];

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	set<int> st;

	int n, m, t;

	cin >> t;
	while (t--){

		cin >> n >> m;
		st.clear();

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cin >> board[i][j];
		}

		int x, y;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				for (int k = 0; k < 8; k++){

					x = i + dx[k]; y = j + dy[k];

					if (x >= 0 && y >= 0 && x < n && y < m){

						if (board[i][j] == board[x][y] && board[i][j] != -1) 
							st.insert(board[x][y]);
					}
				}// k
			}// j
		}// i

		cout << st.size() << endl;
	}// t

	return 0;
}
