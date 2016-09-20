#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = (int) s1.length(), n = (int) s2.length();
        
        if (m + n != s3.size()) return false;
        
        vector<vector<bool>> dp(m+1);
        for (int i = 0; i <= m; ++i) {
            dp[i].resize(n+1);
        }
        
        dp[0][0] = true;
        for (int i = 0; i < m; ++i) {
            dp[i+1][0] = dp[i][0] && s1[i] == s3[i];
        }
        
        for (int j = 0; j < n; ++j) {
            dp[0][j+1] = dp[0][j] && s2[j] == s3[j];
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1])
                             || (dp[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        
        return dp[m][n];
    }
};

void Test0()
{
    Solution sln;
    cout << sln.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << sln.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    //cout << sln.isInterleave("aabcc", "", "") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
