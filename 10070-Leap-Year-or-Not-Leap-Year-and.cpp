#include <bits/stdc++.h>
using namespace std;

bool mod(string num, lli n){

	lli remainder = 0;

	for (int i = 0; i < num.size(); ++i)
		remainder = (remainder * 10 + num[i] - '0') % n;

	return remainder == 0;
}

int main(){

	freopen("in.txt", "r", stdin);

	string year;
	int c = 0;
	
	while (cin >> year){

		if (c++ > 0) cout << endl;

		bool isLeapYear = mod(year, 4) && (mod(year, 400) || !mod(year, 100));
		bool isSpecial = isLeapYear;

		if (isLeapYear)
			printf("This is leap year.\n");

		if (mod(year, 15))
		{
			printf("This is huluculu festival year.\n");
			isSpecial = true;
		}

		if (mod(year, 55) && isLeapYear)
			printf("This is bulukulu festival year.\n");

		if (!isSpecial)
			printf("This is an ordinary year.\n");

	}

	return 0;
}
