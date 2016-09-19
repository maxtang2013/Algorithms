#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        
        getNext(s);
        
        int i = 0, j = (int) s.length() - 1;
        
        while (j > i) {
            if (i == -1 || s[i] == s[j]) {
                --j;
                ++i;
            } else {
                i = next[i];
            }
        }
        
        if (i == j) j = i * 2 + 1;
        else j = i * 2;
        
        string t = s.substr(j);
        reverse(t.begin(), t.end());
        
        return t + s;
    }
    
private:
    void getNext(string s) {
        int n = (int) s.length();
        next.resize(s.length());
        next[0] = -1;
        int j = -1;
        int i = 0;
        while (i < n - 1) {
            if ( j == -1 || s[j] == s[i]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
    }
    vector<int> next;
};

void Test0()
{
    Solution sln;
//    cout << sln.shortestPalindrome("abcd") << endl;
//    cout << sln.shortestPalindrome("") << endl;
    cout << sln.shortestPalindrome("aacecaaa") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
