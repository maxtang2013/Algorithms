#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.length();
        int mask = 0;
        int len = 0, maxLen = 0;
        int lastIndexForLetter[256];
        for (int i = 0; i < 256; ++i) {
            lastIndexForLetter[i] = -1;
        }
        
        for (int i = 0; i < n; ++i) {
            len = min(len + 1, i - lastIndexForLetter[s[i]]);
            maxLen = max(maxLen, len);
            lastIndexForLetter[s[i]] = i;
        }
        return maxLen;
    }
};

void Test0()
{
    Solution sln;
    printf("%d\n", sln.lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", sln.lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", sln.lengthOfLongestSubstring("pwwkew"));
    printf("%d\n", sln.lengthOfLongestSubstring("iur1rudud"));
}

int main()
{
    Test0();
    
    return 0;
}
