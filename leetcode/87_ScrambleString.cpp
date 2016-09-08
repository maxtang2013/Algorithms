#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = (int) s1.length();
        
        if (m == 1) return s1 == s2;
        
        string s = s1 + s2;
        if (mIsScramble.count(s) > 0) {
            return mIsScramble[s];
        }
        
        bool ans = false;
        
        // Counting character helps.
        // For the largest test case, it reduces the runtime from 430ms to 6ms.
        
        int cnt1[26] = {0}, cnt2[26] = {0}, cnt3[26] = {0};
        for (int leftLen = 1; leftLen < m; ++leftLen) {
            
            string x1 = s1.substr(0, leftLen);
            string x2 = s1.substr(leftLen, m - leftLen);
            
            cnt1[s1[leftLen-1]-'a']++;
            cnt2[s2[leftLen-1]-'a']++;
            cnt3[s2[m-leftLen]-'a']++;
            
            int i = 0;
            for (i = 0; i < 26; ++i) {
                if (cnt1[i] != cnt2[i]) {
                    break;
                }
            }
            
            if (i == 26 && isScramble(x1, s2.substr(0, leftLen))
                && isScramble(x2, s2.substr(leftLen, m-leftLen))) {
                ans = true;
                break;
            }
            
            for (i = 0; i < 26; ++i) {
                if (cnt1[i] != cnt3[i]) {
                    break;
                }
            }
            
            if (i == 26 && isScramble(x1, s2.substr(m-leftLen, leftLen))
                && isScramble(x2, s2.substr(0, m-leftLen)))
            {
                ans = true;
                break;
            }
        }
        
        return mIsScramble[s] = ans;
    }
private:
    map<string, bool> mIsScramble;
};

void Test0()
{
    Solution sln;
    
    cout << sln.isScramble("great", "rgtae") << endl;
    cout << sln.isScramble("great", "rgtea") << endl;
    cout << sln.isScramble("great", "tearg") << endl;
    cout << sln.isScramble("great", "rtgea") << endl;
    cout << sln.isScramble("great", "rtega") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
