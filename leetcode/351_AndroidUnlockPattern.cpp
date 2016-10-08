#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

//Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
//
//Rules for a valid pattern:
//
//Each pattern must connect at least m keys and at most n keys.
//All the keys must be distinct.
//If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
//The order of keys used matters.
//Invalid move: 4 - 1 - 3 - 6
//Line 1 - 3 passes through key 2 which had not been selected in the pattern.
//
//Invalid move: 4 - 1 - 9 - 2
//Line 1 - 9 passes through key 5 which had not been selected in the pattern.
//
//Valid move: 2 - 4 - 1 - 3 - 6
//Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
//
//Valid move: 6 - 5 - 4 - 1 - 9 - 2
//Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
//
//Example:
//Given m = 1, n = 1, return 9.
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return dfs(m, n, 0, 1, 1);
    }
    
private:
    int dfs(int m, int n, int mask, int prevI, int prevJ) {
        int count = m <= 0;
        if (n <= 0) return count;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int I = prevI + i, J = prevJ + j;
                int newMask = mask | (1<<(i*3+j));
                if (newMask == mask) continue;
                if (I%2==0 && J%2==0 && ((newMask & (1<<(I/2*3+J/2))) == 0)) continue;
                
                count += dfs(m-1, n-1, newMask, i, j);
            }
        }
        return count;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.numberOfPatterns(1, 1) << endl;
    cout << sln.numberOfPatterns(2, 2) << endl;
    cout << sln.numberOfPatterns(3, 3) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
