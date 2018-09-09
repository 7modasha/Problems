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

const int N = 200200;

int f[N];
vector<int> v;

void build(const string &p){

    int j = 0;
    for(int i = 1; i < p.size(); ++i){

        while(j > 0 and p[i] != p[j]) j = f[j-1];
        if(p[i] == p[j]) ++j;
        f[i] = j;
    }
}

void search(const string &s, const string &p){

    build(p);
    int j = 0;
    for(int i = 0; i < s.size(); ++i){

        while(j > 0 and s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) ++j;

        if(j == p.size()){
            v.push_back(i-j+1);
            j = f[j-1]; 
        }
    }
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

        p = s; s += s;
        reverse(all(p));

        v.clear();
        search(s, p);

        if(v.size() == 0)
            cout << "simple\n";
        else if(v.size() == 2 and v[0] == 0 and v[1] == p.size())
            cout << "palindrome\n";
        else
            cout << "alindrome\n";
    }
    return 0;
}