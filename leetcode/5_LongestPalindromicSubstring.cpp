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
    string longestPalindrome1(string s) {
        int n = (int)s.length();
        if (n < 2) return s;
        
        bool** isPalindrome = new bool*[2];
        for (int i = 0; i < 2; ++i) {
            isPalindrome[i] = new bool[n];
            memset(isPalindrome[i], -1, sizeof(bool)*n);
        }
        
        int maxLen = 1, maxLenStart = 0;
        for (int l = 2; l <= n; ++l) {
            int idx = l%2;
            for (int i = 0; i < n; ++i) {
                if (i+l-1 < n && s[i] == s[i+l-1]) {
                    isPalindrome[idx][i] = isPalindrome[idx][i+1];
                    if (isPalindrome[idx][i] && maxLen < l) {
                        maxLen = l;
                        maxLenStart = i;
                    }
                } else {
                    isPalindrome[idx][i] = false;
                }
            }
        }
        for (int i = 0; i <2; ++i) {
            delete[] isPalindrome[i];
        }
        delete[] isPalindrome;
        return s.substr(maxLenStart, maxLen);
    }
    
    string longestPalindrome(string s) {
        
        if (s.empty()) return s;
        
        int maxLength=1, maxLenEnd=0;
        for (int i = 1; i < s.length(); ++i) {
            int len = maxLength;
            if (i - maxLength >= 0 && isPalindrome(s, i - maxLength, i)) {
                len = maxLength + 1;
            }
            
            if (i - maxLength - 1 >= 0 && isPalindrome(s, i - maxLength - 1, i))
            {
                len = maxLength + 2 ;
            }
            
            if (len > maxLength) {
                maxLength = len;
                maxLenEnd = i;
            }
        }
        return s.substr(maxLenEnd - maxLength + 1, maxLength);
    }
    
private:
    bool isPalindrome(string&s, int start, int end)
    {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};


void Test0()
{
    Solution sln;
    cout << sln.longestPalindrome("aaaabaaa") << endl;
    cout << sln.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
