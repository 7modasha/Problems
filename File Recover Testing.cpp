#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<sstream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>

#define ll long long
#define oo 0x3f3f3f3f
#define mod  1000000007LL
#define lmod 1000000000039LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 2000100;

vector<int> f;
void build(const string &p){

    int j = 0;
    f.assign(p.size(), 0);
    for(int i = 1; i < p.size(); ++i){
        while(j > 0 and p[i] != p[j]) j = f[j-1];
        if(p[i] == p[j]) ++j;
        f[i] = j;
    }
}

int search(string s, const string &p){

    int j = 0, ans = 0; build(p);
    for(int i = 0; i < s.size(); ++i){

        while(j > 0 and s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) ++j;
        if(j == p.size()){
            ++ans; j = f[j-1];
        }
    }
    return ans;
}

char str[N];

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    string s;
    while(scanf("%d %s", &n, str) and n > 0){
        s = str;
        if(n < s.size()){
            puts("0"); continue;
        }

        build(s);
        int x = s.size() - f[s.size()-1];
        x = (n - f[s.size()-1]) / x;

        printf("%d\n", x);
    }
    
    return 0;
}