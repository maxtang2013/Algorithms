#include <iostream>

class Solution {
public:
    int totalNQueens(int n) {
        int i;
        for (i = 0; i < n; ++i)
            mQueenPos[i] = -1;

        return helper(0, n);
    }
private:
    int helper(int i, int n) {
        int j, k, res = 0;
        bool valid = true;
        
        if (i == n) {
            return 1;
        }

        for (j = 0; j < n; ++j)
        {
            if (mQueenPos[j] == -1)
            {
                mQueenPos[j] = i;
                valid = true;
                
                for (k = 0; k < n; ++k)
                {
                    if (mQueenPos[k] == i || mQueenPos[k] == -1)
                    {
                        continue;
                    }
                    
                    if (i - mQueenPos[k] == j - k
                      ||i - mQueenPos[k] == k - j)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    res += helper(i + 1, n);
                }
                mQueenPos[j] = -1;
            }
        }
        return res;
    }

private:
    int mQueenPos[32];
};

int main()
{
    Solution sln;
    for (int i = 0; i < 8; ++i)
    {
        printf("totalNQueens(%d) = %d.\n", i+1, sln.totalNQueens(i+1));
    }
}

