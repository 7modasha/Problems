#include <bits/stdc++.h>
using namespace std;

int main(){

	//freopen("in.txt", "r", stdin);

	int n;
	
	while (cin >> n && n){

		queue<int> qu;

		for (int i = 1; i <= n; i++) qu.push(i);

		cout << "Discarded cards:";

		for (int c = 0; qu.size() != 1; c++){

			switch (c % 2 == 0){

			case 1:
				cout << ' ' << qu.front();
				if (qu.size() != 2) cout << ',';
				qu.pop(); break;

			case 0:
				qu.push(qu.front());
				qu.pop();
				break;
			}
		}

		cout << "\nRemaining card: " << qu.front() << endl;
	}

	return 0;
}
