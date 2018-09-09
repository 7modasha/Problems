#include <bits/stdc++.h>

using namespace std;

char getChar(string &s){

	char ans = 0;
	s = s.substr(1, s.find('.')-1) + s.substr(s.find('.')+1, 3);

	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'o') ans = ans | (1<<i);
	}

	return ans;
}

int main(){
 
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int cnt = 0;
	string line;
	while(cnt != 2){
		getline(cin, line);

		if(line[0] == '_'){
			++cnt; continue;
		}
		cout << getChar(line);
	}
	
	return 0;
}