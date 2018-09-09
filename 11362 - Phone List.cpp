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

const int N = 10100;

string a[N];
set<string> st;

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

    int t, n, isConsistant;

    cin >> t;
    while(t-- > 0){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a+n, [](string &a, string &b){
            return a.size() < b.size();
        });

        string s;
        st.clear();
        isConsistant = true;
        for(int i = 0; i < n and isConsistant; ++i){
            s = "";
            for(int j = 0; j < a[i].size() and isConsistant; ++j){
                s += a[i][j];
                if(st.count(s))
                    isConsistant = false;
            }
            st.insert(s);
        }

        if(isConsistant)
            cout << "YES\n";
        else
            cout << "NO\n";    
    }
    

    return 0;
}