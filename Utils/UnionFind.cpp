class UnionFind {
public:
    
    UnionFind(int N) {
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    ~UnionFind() {
        delete []id;
        delete []sz;
    }
    
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        
        if (i == j) return;
        
        if (sz[i] > sz[j]) {
            id[j] = i;
            sz[i] += sz[j];
        } else {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
    
    int getSize(int i) {
        int r = root(i);
        return sz[r];
    }
    
private:
    
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
private:
    
    int* id;
    int* sz;
};
