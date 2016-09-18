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
        
        while (j > i*2) {
            if (s[i] == s[j-i]) ++i;
            else {
                j = j - (i - next[i]);
                i = next[i] == -1 ? 0 : next[i];
            }
        }
        
        string t = s.substr(j + 1);
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
    cout << sln.shortestPalindrome("abcd") << endl;
    cout << sln.shortestPalindrome("") << endl;
    cout << sln.shortestPalindrome("aacecaaa") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
