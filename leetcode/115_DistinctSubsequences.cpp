#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
        int m = (int)s.length(), n = (int)t.length();
        
        vector<vector<int>> num(2);
        for (int i = 0; i < 2; ++i) {
            num[i].resize(n+1);
        }
        
        num[0][0] = 1;
        num[1][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            int k = i % 2;
            
            for (int j = 0; j < n; ++j) {
                num[1-k][j+1] = num[k][j+1];
                if (s[i] == t[j]) {
                    num[1-k][j+1] += num[k][j];
                }
            }
        }
        return num[m%2][n];
    }
};


void Test0()
{
    Solution sln;
    cout << sln.numDistinct("habbbit", "habit") <<endl;
    cout << sln.numDistinct("ccc", "c") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
