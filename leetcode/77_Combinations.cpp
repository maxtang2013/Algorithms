#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        mAns.clear();
        mN = n;
        mK = k;
        if (k <= n) {
            mComb.resize(k);
            traverse(1, k);
        }
        return mAns;
    }
    
private:
    void traverse(int i, int k) {
        if (k == 0) {
            mAns.push_back(mComb);
            return;
        }
        
        for (int j = i; j <= mN - k + 1; ++j) {
            mComb[mK - k] = j;
            traverse(j+1, k-1);
        }
    }
    
    int mK;
    int mN;
    vector<vector<int>> mAns;
    vector<int> mComb;
};

template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}


void Test0()
{
    Solution sln;
    printBoard(sln.combine(4, 2));
}

int main()
{
    Test0();
    
    return 0;
}
