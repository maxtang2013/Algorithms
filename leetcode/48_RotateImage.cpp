#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //  1, 2, 3, 4, 5
        //  6, 7, 8, 9, 10
        //  11,12,13,14,15
        //  16,17,18,19,20
        //  21,22,23,24,25
        
        // A[i][j] = A[n-1-j][i]
        
        // A[4][0] = A[0][0]
        // A[4][4] = A[0][4]
        // A[3][4] = A[0][3]
        
        // A[1][2] = A[5-1-2][1]
        // A[3][1] = A[5-1-1][3]
        int n = matrix.size();
        
        int midRow = (n+1) / 2;
        int midCol = (n+1) / 2;
        if (n % 2 == 1) --midCol;
        
        for (int i = 0; i < midRow; ++i) {
            for (int j = 0; j < midCol; ++j) {
                int r = i, c = j;
                int t = matrix[i][j];
                
                do {
                    if (n-1-c == i && r == j) {
                        matrix[r][c] = t;
                        break;
                    }
                    
                    matrix[r][c] = matrix[n-1-c][r];
                    int x = r;
                    r = n-1-c;
                    c = x;
                } while (true);
            }
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
        {1,2},
        {3,4},
    };
    
    sln.rotate(m);
    printBoard(m);
}

void Test1()
{
    Solution sln;
    vector<vector<int>> m = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    
    sln.rotate(m);
    printBoard(m);
}


int main()
{
    Test0();
    Test1();
    
    return 0;
}
