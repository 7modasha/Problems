class UFDS {

    int numSets;
    vector<int> p, rank, setSize;

public:

    UFDS(int n) {
        numSets = n;
        p.assign(n, 0);
        rank.assign(n, 0);
        setSize.assign(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
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
