#include <bits/stdc++.h>
using namespace std;

struct People{

	string name;
	int d, m, y;

};

bool cpr(People a, People b){

	if (a.y != b.y)
		return a.y > b.y;

	if (a.m != b.m)
		return a.m > b.m;

	return a.d > b.d;
}

int main(){

	//freopen("in.txt", "r", stdin);

	int n;
	People ppl[101];

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> ppl[i].name >> ppl[i].d >> ppl[i].m >> ppl[i].y;

	sort(ppl, ppl + n, cpr);

	cout << ppl[0].name << endl;

	cout << ppl[n-1].name << endl;

	return 0;
}
