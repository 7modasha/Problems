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
char p[N];

void build(int n){

    int j = 0;
    for(int i = 1; i < n; ++i){

        while(j > 0 and p[i] != p[j]) j = f[j-1];
        if(p[i] == p[j]) ++j;
        f[i] = j;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    int T, n, cnt = 1;
    scanf("%d", &T);
    while(T-- > 0){
        printf("Test case #%d\n", cnt++);
        scanf("%d%s", &n, p);

        build(n);
        for(int i = 0; i < n; ++i){
            if(2 * f[i] > i){
                int k = (i+1) - f[i];

                if((i+1)%k == 0)
                    cout << i+1 << " " << (i+1)/k << "\n";
            }
        }
        if(T) puts("");
    }

    return 0;
}