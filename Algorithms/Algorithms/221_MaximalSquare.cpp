#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    // Given a 2D binary matrix filled with 0's and 1's,
    // find the largest square containing only 1's and return its area.
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        int ans = 0;
        int prev = 0;
        vector<int> maxSquareLen(n+1);
        
        for (int i = 1; i <= m; ++i) {
            prev = 0;
            for (int j = 1; j <= n; ++j) {
                int tmp = maxSquareLen[j];
                if (matrix[i-1][j-1] == '1') {
                    maxSquareLen[j] = min(maxSquareLen[j], min(maxSquareLen[j-1], prev)) + 1;
                    ans = max(ans, maxSquareLen[j]);
                } else {
                    // It's neccesary to do this here!!!
                    maxSquareLen[j] = 0;
                }
                prev = tmp;
            }
        }
        return ans * ans;
    }
    
    // A O(m * n) solutioin.
    // We can reduce the memory usage to O(n).
    int maximalSquare_Mine(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        int ans = 0;
        vector<vector<int>> maxSquareLen(m);
        vector<int> upper(n, -1);
        
        for (int i = 0; i < m; ++i)
            maxSquareLen[i].resize(n);
        
        for (int i = 0; i < m; ++i) {
            int left = -1;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    left = j;
                    upper[j] = i;
                    continue;
                }
                
                if (i > 0 && j > 0) {
                    int l = maxSquareLen[i-1][j-1];
                    
                    l = min(l+1, j-left);
                    l = min(l, i - upper[j]);
                    maxSquareLen[i][j] = l;
                } else {
                    maxSquareLen[i][j] = 1;
                }
                
                ans = max(ans, maxSquareLen[i][j]);
            }
        }
        return ans * ans;
    }
    
    // O(m * n * min(m, n))
    int maximalSquare_O_N_3(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        int ans = 0;
        vector<vector<int>> maxSquareLen(m);
        
        for (int i = 0; i < m; ++i)
            maxSquareLen[i].resize(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                
                if (i > 0 && j > 0) {
                    int l = maxSquareLen[i-1][j-1];
                    
                    int k = 1;
                    for (; k <= l; ++k) {
                        if (matrix[i-k][j] == '0' || matrix[i][j-k] == '0') break;
                    }
                    maxSquareLen[i][j] = k;
                } else {
                    maxSquareLen[i][j] = 1;
                }
                
                ans = max(ans, maxSquareLen[i][j]);
            }
        }
        return ans * ans;
    }

};

void Test0()
{
    Solution sln;
    vector<vector<char>> m = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << sln.maximalSquare(m) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
