#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            mRowMask[i] = mColMask[i] = mBlockMask[i] = 0;
        }
        mSolved = false;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int block = i/3 * 3 + j/3;
                
                if (board[i][j] != '.') {
                    mRowMask[i] |= 1 << (board[i][j] - '0');
                    mColMask[j] |= 1 << (board[i][j] - '0');
                    mBlockMask[block] |= 1 << (board[i][j] - '0');
                }
            }
        }
        
        fill(board, 0, 0);
    }
    
private:
    void fill(vector<vector<char>> &board, int i, int j) {
        if (i >= 9){
            mSolved = true;
            return;
        }
        if (board[i][j] != '.') {
            moveToNextPosition(i, j);
            fill(board, i, j);
            return;
        }
        
        int block = i/3 * 3 + j/3;
        
        for (int k = 1; k < 10; ++k) {
            int m = (1<<k);
            if ((mRowMask[i] & m) == 0 && (mColMask[j] & m) == 0) {
                
                if ((mBlockMask[block] & m) == 0) {
                    board[i][j] = (char) (k + '0');
                    
                    mRowMask[i] |= m;
                    mColMask[j] |= m;
                    mBlockMask[block] |= m;
                    
                    int ni = i, nj = j;
                    moveToNextPosition(ni, nj);
                    
                    fill(board, ni, nj);
                    
                    if (!mSolved)
                    {
                        mRowMask[i] ^= m;
                        mColMask[j] ^= m;
                        mBlockMask[block] ^= m;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
    
    void moveToNextPosition(int &i, int&j) {
        ++j;
        if (j == 9) {
            j = 0;
            ++i;
        }
    }
    
private:
    int mRowMask[9];
    int mColMask[9];
    int mBlockMask[9];
    
    bool mSolved;
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
}

void Test0()
{
    Solution sln;
    
    vector<vector<char>> board = {
        {'5','3', '.', '.', '7', '.', '.', '.', '.'},
        {'6','.', '.', '1', '9', '5', '.', '.', '.'},
        {'.','8', '9', '.', '.', '.', '.', '6', '.'},
        {'8','.', '.', '.', '6', '.', '.', '.', '3'},
        {'4','.', '.', '8', '.', '3', '.', '.', '1'},
        {'7','.', '.', '.', '2', '.', '.', '.', '6'},
        {'.','6', '.', '.', '.', '.', '2', '8', '.'},
        {'.','.', '.', '4', '1', '9', '.', '.', '5'},
        {'.','.', '.', '.', '8', '.', '.', '7', '9'},
    };
    
    sln.solveSudoku(board);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Test0();
    
    return 0;
}
