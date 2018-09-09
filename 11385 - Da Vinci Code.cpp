#include<iostream>
#include<stdio.h>
#include<math.h>
#include<sstream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100100;

string s, t;
char ans[200];
ll n, a[200], fib[200];
map<ll, int> rev;

void calcFib(){

    fib[0] = fib[1] = 1; 
    for (int i = 2; i <= 85; ++i)
        fib[i] += fib[i-1] + fib[i-2];
    
    for(int i = 1; i <= 85; ++i)
        rev[fib[i]] = i;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    calcFib();

    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        cin.ignore();
        getline(cin, s);

        t = "";
        for(int i = 0; i < s.size(); ++i)
            if(s[i] >= 'A' and s[i] <= 'Z') t += s[i];
        
        int mx = 0;
        fill(ans, ans+200, ' ');
        for(int i = 0; i < n; ++i){
            mx = max(mx, rev[a[i]]-1);
            ans[rev[a[i]]-1] = t[i];
        }

        for(int i = 0; i <= mx; ++i)
            putchar(ans[i]);
        puts("");
    }


    return 0;
}