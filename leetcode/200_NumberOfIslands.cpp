#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class UnionFind {
public:
    UnionFind(int capacity)
    :mSize(capacity, 1), mParent(capacity)
    {
        for (int i = 0; i < capacity; ++i) {
            mParent[i] = i;
        }
        mCount = capacity;
    }
public:
    void Unite(int i, int j) {
        int root1 = Root(i), root2 = Root(j);
        if (root1 != root2) {
            if (mSize[root1] > mSize[root2]) {
                mParent[root2] = root1;
                mSize[root1] += mSize[root2];
            } else {
                mParent[root1] = root2;
                mSize[root2] +=  mSize[root1];
            }
            
            --mCount;
        }
    }
    
    int GetCount() { return mCount; }
    
private:
    int Root(int i) {
        while (mParent[i] != i) {
            mParent[i] = mParent[mParent[i]];
            i = mParent[i];
        }
        return i;
    }
    
private:
    vector<int> mParent;
    vector<int> mSize;
    int mCount;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        UnionFind uf(m*n);
        
        int countZero = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int idx = i * n + j;
                    if (i > 0 && grid[i-1][j] == '1') {
                        uf.Unite(idx, idx-n);
                    }
                    if (j > 0 && grid[i][j-1] == '1') {
                        uf.Unite(idx, idx-1);
                    }
                } else ++countZero;
            }
        }
        return uf.GetCount() - countZero;
    }
};

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    cout << (1<<30) << endl;
    
    return 0;
}
