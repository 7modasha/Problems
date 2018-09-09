#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 10100;

class UFDS {

    int n;
    vector<int> p;

public:

    UFDS(int _n) {
        n = _n;
        p.assign(2*n, 0);
        for (int i = 0; i < 2*n; ++i)
            p[i] = i;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool setFriends(int i, int j){

        if(areEnemies(i, j)) return false;

        p[findSet(i)] = findSet(j);
        p[findSet(i+n)] = findSet(j+n);
        return true;
    }

    bool setEnemies(int i, int j){
        if(areFriends(i, j)) return false;

        p[findSet(i)] = findSet(j+n);
        p[findSet(j)] = findSet(i+n);
        return true;
    }

    bool areEnemies(int i, int j){
        return findSet(i) == findSet(j+n) 
            and findSet(j) == findSet(i+n);
    }
    bool areFriends(int i, int j){
        return findSet(i) == findSet(j) 
            and findSet(i+n) == findSet(j+n);
    }
};


int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    int n, c, x, y;
    scanf("%d", &n);

    UFDS dsu(n);
    while(scanf("%d%d%d", &c, &x, &y) and c != 0){
        if(c == 1){
            if(!dsu.setFriends(x, y)) puts("-1");
        } else if(c == 2){
            if(!dsu.setEnemies(x, y)) puts("-1");
        } else if(c == 3){
            puts(dsu.areFriends(x, y) ? "1" : "0");
        } else if(c == 4){
            puts(dsu.areEnemies(x, y) ? "1" : "0");
        }
    }
    
    return 0;
}