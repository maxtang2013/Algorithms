#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            mRowMask[i] = mColMask[i] = mBlockMask[i] = 0;
        }
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int block = i/3 * 3 + j/3;
                
                if (board[i][j] != '.') {
                    
                    int m = 1 << (board[i][j] - '0');
                    
                    if ((mRowMask[i] & m) != 0 || (mColMask[j] & m) != 0 || (mBlockMask[block] & m) != 0)
                        return false;
                    
                    mRowMask[i] |= m;
                    mColMask[j] |= m;
                    mBlockMask[block] |= m;
                }
            }
        }
        return true;
    }
    
private:
    int mRowMask[9];
    int mColMask[9];
    int mBlockMask[9];
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

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
}

int main()
{
    Test0();
    
    return 0;
}
