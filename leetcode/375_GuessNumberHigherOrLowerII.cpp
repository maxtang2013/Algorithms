#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

//We are playing the Guess Game. The game is as follows:
//
//I pick a number from 1 to n. You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
//
//Example:
//
//n = 10, I pick 8.
//
//First round:  You guess 5, I tell you that it's higher. You pay $5.
//Second round: You guess 7, I tell you that it's higher. You pay $7.
//Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
//Game over. 8 is the number I picked.
//
//You end up paying $5 + $7 + $9 = $21.
//Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.



class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1);
        
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(n);
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int val = INT_MAX;
                for (int j = i; j < i+len; ++j) {
                    val = min(val, (j+1) + max(dp[j-i][i], dp[len-(j-i)-1][j+1]));
                }
                dp[len][i] = val;
            }
        }
        return dp[n][0];
    }
};


void Test0()
{
    Solution sln;
    cout << sln.getMoneyAmount(10) << endl;
    cout << sln.getMoneyAmount(3) << endl;
    cout << sln.getMoneyAmount(4) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
