#include<iostream>
#include<stdio.h>
#include<math.h>
#include<sstream>
#include<memory.h>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 1000000007LL
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 1100;

int ppl[N][N];
int x, y, used[N];

class UFDS {

    vector<int> p, rank, setSize;
    int numSets;

public:

    UFDS(int N) {
        numSets = N;
        rank.assign(N+1, 0);
        p.assign(N+1, 0);
        for (int i = 1; i <= N; i++)
            p[i] = i;
        setSize.assign(N+1, 1);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {

        if(isSameSet(i, j)) return;

        int x = findSet(i), y = findSet(j);
        if(rank[x] < rank[y])
            swap(x, y);

        if (rank[x] == rank[y])
            rank[x]++;

        p[y] = x;
        setSize[findSet(x)] += setSize[findSet(y)];
        --numSets;
    }

    int nSets() {
        return numSets;
    }
};


bool read(){
    string s;
    getline(cin, s);
    if(s == "") return false;

    stringstream ss(s);
    ss >> x; ss >> y;

    return true;
}

void clear(){
    memset(used, 0, sizeof used);
    memset(ppl, 0, sizeof ppl);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);

    int t, n = 0;
    cin >> t;
    cin.ignore();

    read();//empty
    while(t-- > 0){

        read();
        int p = x, n = y;

        UFDS ds(p);
        while(read())
            ppl[x][y] = 1;
        
        for(int i = 1; i <= p; ++i){

            for(int j = i+1; j <= p; ++j){
                int cnt = 0;
                for(int k = 1; k <= n; ++k)
                    if(ppl[i][k] != ppl[j][k]) ++cnt;
                
                if(cnt == 0)
                    ds.unionSet(i, j);
            }
        }

        printf("%d\n", ds.nSets());
        if(t) puts("");
        clear();
    }
    
    return 0;
}