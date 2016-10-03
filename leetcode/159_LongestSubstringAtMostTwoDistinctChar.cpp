#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int cnt[256] = {0};
        int numDistinct = 0;
        int n = (int) s.length();
        int i = 0, j = 0, ans = 0;
        
        while ( j<n || numDistinct > 2 ) {
            if (numDistinct <= 2) {
                ans = max(ans, j - i);
                if (cnt[s[j++]]++ == 0) ++numDistinct;
            } else {
                if (cnt[s[i++]]-- == 1) --numDistinct;
            }
        }
        return ans;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.lengthOfLongestSubstringTwoDistinct("eeraddraaddrdddddaea") << endl;
    cout << sln.lengthOfLongestSubstringTwoDistinct("") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
