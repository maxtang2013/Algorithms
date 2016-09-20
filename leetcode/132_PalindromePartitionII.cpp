#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
public:
    int minCut(string s) {
        int n = (int) s.length();
        vector<vector<bool>> isPalindrome(n+1);
        for (int i = 0; i <= n; ++i) {
            isPalindrome[i].resize(n);
        }
        
        for (int i = 0; i < n; ++i) {
            isPalindrome[1][i] = isPalindrome[0][i] = true;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                isPalindrome[len][i] = s[i] == s[i+len-1] && isPalindrome[len-2][i+1];
            }
        }
        
        // Only consider minimum cuts for ranges [0, i], i = 0, 1, ..., n
        vector<int> minCuts(n);
        for (int end = 0; end < n; ++end) {
            int minCut = end;
            if (isPalindrome[end+1][0]) {
                minCuts[end] = 0;
                continue;
            }
            for (int i = 1; i <= end; ++i) {
                if (isPalindrome[end-i+1][i]) {
                    minCut = min(minCut, minCuts[i-1] + 1);
                }
            }
            minCuts[end] = minCut;
        }
        
        return minCuts[n-1];
    }
    
    int minCut_O_N_3(string s) {
        int n = (int) s.length();
        vector<vector<bool>> isPalindrome(n+1);
        for (int i = 0; i <= n; ++i) {
            isPalindrome[i].resize(n);
        }
        
        for (int i = 0; i < n; ++i) {
            isPalindrome[1][i] = isPalindrome[0][i] = true;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                isPalindrome[len][i] = s[i] == s[i+len-1] && isPalindrome[len-2][i+1];
            }
        }
        
        vector<vector<int>> minCuts(n+1);
        
        for (int i = 0; i <= n; ++i) {
            minCuts[i].resize(n, n);
        }
        
        for (int len = 0; len <= n; ++len) {
            for (int i = 0; i <= n - len && i < n; ++i) {
                if (isPalindrome[len][i]) {
                    minCuts[len][i] = 0;
                }
            }
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                for (int len2 = 1; len2 < len; ++len2) {
                    if (isPalindrome[len2][i]) {
                        minCuts[len][i] = min(minCuts[len][i], 1+minCuts[len-len2][i+len2]);
                    }
                }
            }
        }
        
        return minCuts[n][0];
    }
};

void Test0()
{
    Solution sln;
    cout << sln.minCut("aa") << endl;
    cout << sln.minCut("arddgrddrdrgood") << endl;
    cout << sln.minCut("ltsqjodzeriqdtyewsrpfscozbyrpidadvsmlylqrviuqiynbscgmhulkvdzdicgdwvquigoepiwxjlydogpxdahyfhdnljshgjeprsvgctgnfgqtnfsqizonirdtcvblehcwbzedsmrxtjsipkyxk") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
