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

vector<string> v;
vector<pair<string, string> > g;

char convertChar(char ch){

    switch(tolower(ch)){
        case 'a':case 'b':case 'c':
            return '2';
        case 'd':case 'e':case 'f':
            return '3';
        case 'g':case 'h':case 'i':
            return '4';
        case 'j':case 'k':case 'l':
            return '5';
        case 'm':case 'n':case 'o':
            return '6';
        case 'p':case 'q':case 'r':case's':
            return '7';
        case 't':case 'u':case 'v':
            return '8';
        case 'w':case 'x':case 'y':case'z':
            return '9';
        default:
            return '-';
    }
}

string convert(string s){

    string ans = "";
    for(int i = 0; i < s.size(); ++i){
        char ch = convertChar(s[i]);
        if(ch != '-') ans += ch;
    }

    return ans;
}

bool search(const string &a, const string &b){
    if(b.size() < a.size()) return false;

    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i]) return false;
    }

    return true;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

    string a, b, c;
    while(cin >> a){

        if(!isdigit(a[0])){
            cin >> b >> c;
            g.push_back(make_pair(convert(a[0] + b), c));
        } else
            v.push_back(a);
    }

    for(int i = 0; i < v.size(); ++i){
        bool exFound = false;
        for(int j = 0; j < g.size(); ++j){
            if(v[i] == g[j].second){
                cout << v[i] << endl;
                exFound = true;
                break;
            }
        }

        if(exFound) continue;
        bool flag = false, found;
        for(int j = 0; j < g.size(); ++j){
            found = search(v[i], g[j].first);
            if(flag and found)
                cout << " ";

            if(found){
                flag = true;
                cout << g[j].second;
            }
        }

        if(flag)
            cout << '\n';
        else
            cout << "0\n";
    }

    return 0;
}