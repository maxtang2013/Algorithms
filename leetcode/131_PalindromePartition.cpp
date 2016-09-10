#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        mPartitionSet.clear();
        vector<string> partition;
        traverse(s, partition);
        return mPartitionSet;
    }
    
private:
    
    void traverse(string s, vector<string>& partition) {
        int n = (int) s.length();
        
        if (n == 0) {
            mPartitionSet.push_back(partition);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            int j = i, k = 0;
            while (k < j) {
                if (s[k] != s[j]) break;
                ++k; --j;
            }
            if (k >= j) {
                partition.push_back(s.substr(0, i+1));
                traverse(s.substr(i+1), partition);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> mPartitionSet;
    
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
    printBoard( sln.partition("aa") );
    
    printBoard( sln.partition("arddgrddrdrgood") );
}

int main()
{
    Test0();
    
    return 0;
}
