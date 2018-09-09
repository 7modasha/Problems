#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<sstream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<map>
#include <unordered_map>
#include <set>

#define ll long long
#define mod  1000000007LL
#define lmod 1000000000039LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 1000100;

int f[N];

void build(const string &p){

    int j = 0;
    for(int i = 1; i < p.size(); ++i){

        while(j > 0 and p[i] != p[j]) j = f[j-1];
        if(p[i] == p[j]) ++j;
        f[i] = j;
    }
}

int search(const string &s, const string &p){

    build(p);
    int j = 0, mx = 0;
    for(int i = 0; i < s.size(); ++i){

        while(j > 0 and s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) ++j;

        mx = max(j, mx);
        if(j == p.size()){
            j = f[j-1]; 
        }
    }

    return mx;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

    int T;
    string s, p;

    cin >> T;
    while(T-- > 0){
        cin >> s;

        p = s; 
        reverse(all(p));
        s = s.substr(0, search(p, s));
        reverse(all(s));

        cout << s << '\n';
    }
    return 0;
}