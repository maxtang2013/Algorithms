#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Cell {
    int i, j;
    int k;
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (word.empty()) return true;
        mBoardRows = (int) board.size();
        mBoardCols = (int) board[0].size();
        
        mWordLen = (int) word.length();
        
        vector<vector<bool>> visited(mBoardRows);
        for (int i = 0; i < mBoardRows; ++i) {
            visited[i].assign(mBoardCols, 0);
        }
        
        for (int i = 0; i < mBoardRows; ++i) {
            for (int j = 0; j < mBoardCols; ++j) {
                if (board[i][j] == word[0]) {
                    
                    visited[i][j] = 1;
                    if (test(board, word, i, j, 1, visited))
                        return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
private:
    
    bool test(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& visited)
    {
        static Cell dirs[] = {{1, 0, 0}, {-1,0,0}, {0,1,0}, {0,-1,0}};
        
        if (k == mWordLen) {
            return true;
        }
        
        for (int t = 0; t < 4; ++t) {
            int i1 = i + dirs[t].i;
            int j1 = j + dirs[t].j;
            if (i1 > -1 && i1 < mBoardRows && j1 > -1 && j1 < mBoardCols
                && !visited[i1][j1]
                && board[i1][j1] == word[k]) {
                visited[i1][j1] = 1;
                
                if (test(board, word, i1, j1, k+1, visited))
                    return true;
                
                visited[i1][j1] = 0;
            }
        }
        return false;
    }
    
    int mBoardRows;
    int mBoardCols;
    int mWordLen;
};

void Test0()
{
    Solution sln;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << sln.exist(board, "SEE") << endl;
    cout << sln.exist(board, "ABCCED") << endl;
}

void Test1()
{
    Solution sln;
    vector<vector<char>> board = {
        {'C','A','A'},
        {'A','A','A'},
        {'B','C','D'}
    };
    cout << sln.exist(board, "AAB") << endl;
    cout << sln.exist(board, "AABCA") << endl;
}

void Test2()
{
    Solution sln;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    cout << sln.exist(board, "ABCESEEEFS") << endl;
    cout << sln.exist(board, "ABCESEEEEFS") << endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    return 0;
}
