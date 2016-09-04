#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        vector<vector<int>> minSum(m);
        for (int i = 0; i < m; ++i)
            minSum[i].resize(n, INT_MAX);
        minSum[0][0] = grid[0][0];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    minSum[i+1][j] = min(minSum[i][j] + grid[i+1][j], minSum[i+1][j]);
                }
                if (j + 1 < n) {
                    minSum[i][j+1] = min(minSum[i][j] + grid[i][j+1], minSum[i][j+1]);
                }
            }
        }
        
        return minSum[m-1][n-1];
    }
};

void Test0()
{
    Solution sln;
    vector<vector<int>> grid = {
        {3, 2},
        {1, 4},
        {1, 1}
    };
    printf("%d\n", sln.minPathSum(grid));
}

void Test1()
{
    Solution sln;
    vector<vector<int>> grid = {
        {2,3,4,2,2,5,5,6,6,3},
        {7,5,6,4,1,7,8,1,7,7},
        {4,0,4,5,4,2,7,8,9,3},
        {7,3,8,3,5,0,9,1,8,7},
        {4,5,4,0,9,5,8,0,8,5},
        {7,4,7,3,0,1,7,9,0,8},
        {5,9,1,5,3,7,6,4,8,6}
    };
    printf("%d\n", sln.minPathSum(grid));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
