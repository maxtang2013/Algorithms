#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        if (mat.empty()) return;
        int m = mat.size(), n = mat[0].size();
        bool col0 = false;
        
        for (int i = 0; i < m; ++i) {
            if (mat[i][0] == 0) col0 = true;
            
            for (int j = 1; j < n; ++j) {
                if (mat[i][j] == 0) {
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j > 0; --j) {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
            if (col0) mat[i][0] = 0;
        }
    }
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
    vector<vector<int>> m = {
        {1}
    };
    sln.setZeroes(m);
    printBoard(m);
}

void Test1()
{
    Solution sln;
    vector<vector<int>> m = {
        {1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
    };
    sln.setZeroes(m);
    printBoard(m);
}

void Test2()
{
    Solution sln;
    vector<vector<int>> m = {
        {0,0,0,5},
        {4,3,1,4},
        {0,1,1,4},
        {1,2,1,3},
        {0,0,1,1}
    };
    sln.setZeroes(m);
    printBoard(m);
}

void Test3()
{
    Solution sln;
    vector<vector<int>> m = {
        {1,1,1},
        {0,1,2}
    };
    sln.setZeroes(m);
    printBoard(m);
}

int main()
{
//    Test0();
//    
//    Test1();
//    Test2();
    Test3();
    
    return 0;
}
