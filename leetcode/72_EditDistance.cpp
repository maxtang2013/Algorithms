#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.length();
        int n = (int)word2.length();
        vector<vector<int>> dis(m+1);
        for (int i = 0; i <= m; ++i) {
            dis[i].resize(n+1);
        }
        
        for (int i = 0; i <= m; ++i) {
            dis[i][0] = i;
        }
        
        for (int j = 0; j <= n; ++j) {
            dis[0][j] = j;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word1[i] == word2[j]) {
                    dis[i+1][j+1] = dis[i][j];
                } else {
                    dis[i+1][j+1] = min(dis[i][j], dis[i+1][j]) + 1;
                    dis[i+1][j+1] = min(dis[i+1][j+1], dis[i][j+1] + 1);
                }
                
            }
        }
        
        return dis[m][n];
    }
};

void Test0()
{
    Solution sln;
    cout << sln.minDistance("abbcdd", "abccd") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
