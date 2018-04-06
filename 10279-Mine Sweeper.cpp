#include <bits/stdc++.h>

#define ll long long

using namespace std;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
char board[100][100];
bool touched[100][100];
char ans[100][100];

int main() {
	
	int n, t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		if (i > 0) cout << endl;

		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		char tmp;
		memset(touched, 0, sizeof touched);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				if (tmp == 'x') touched[i][j] = true;
			}

		int nx, ny, counter, mineTouched = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (touched[i][j]) {

					if (board[i][j] == '*') mineTouched = 1;

					counter = 0;
					for (int k = 0; k < 8; k++) {
						nx = i + dx[k];
						ny = j + dy[k];

						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {

							if (board[nx][ny] == '*') counter++;
						}
					}//k for

					ans[i][j] = counter + '0';
				}
				else
					ans[i][j] = '.';
			}//j for
		} //i for

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (board[i][j] == '*' && mineTouched)
					cout << '*';
				else
					cout << ans[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}