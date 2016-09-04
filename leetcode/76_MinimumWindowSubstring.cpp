#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


// The key to solve this problem is that we can record the k-th occurrence of each character in string s.
class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.length();
        
        // index[baseIndex[cha] + k - 1] is the index of the k-th occurence of character 'cha' in string s.
        vector<int> index(n);
        vector<int> baseIndex(256, -1);
        
        vector<int> charCnt(256, 0);
        vector<int> targetCharCnt(256, 0);
        
        if (t == "") return "";
        
        // Count the number of occurrence of each character.
        for (int i = 0; i < n; ++i) {
            ++charCnt[s[i]];
        }
        
        // Assign base indices for every character.
        baseIndex[0] = 0;
        for (int i = 0; i < 255; ++i) {
            baseIndex[i+1] = baseIndex[i] + charCnt[i];
        }
        
        // Record the index of the k-th occurrence of each character in string s.
        charCnt.assign(256, 0);
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            index[baseIndex[c] + charCnt[c]++] = i;
        }
        
        int m = (int)t.size();
        for (int i = 0; i < m; ++i) {
            targetCharCnt[t[i]]++;
        }
        
        for (int i = 0; i < 256; ++i) {
            if (targetCharCnt[i] > charCnt[i]) {
                return "";
            }
        }
        
        int minLen = n;
        int minStart = 0;
        
        vector<int> cnt(256);
        
        int len = 0;
        for (int i = 0; i < 256; ++i) {
            
            if (targetCharCnt[i] == 0) continue;
            
            len = max(index[baseIndex[i] + targetCharCnt[i] - 1] + 1, len);
        }
        minLen = len;
        
        int tail = len - 1;
        
        for (int i = 1; i < n; ++i) {
            
            char c = s[i-1];
            ++cnt[c];
            
            // If there isn't enough character 'c' in the remaining string, break.
            if (targetCharCnt[c] > charCnt[c] - cnt[c]) break;
            
            if (targetCharCnt[c] > 0) {
                
                // As there had already been cnt[c] occurrences of character 'c' in range[0, i),
                // the tail should be extended far enough to include enough 'c'.
                int newTail = index[baseIndex[c] + cnt[c] + targetCharCnt[c] - 1];
                
                tail = max(newTail, tail);
            }
            
            len = tail - i + 1;
            
            if (len < minLen) {
                minLen = len;
                minStart = i;
            }
        }
        
        return s.substr(minStart, minLen);
    }
};

void Test0()
{
    Solution sln;
    
    cout << sln.minWindow("ADOBECODEBANC", "ABC") << endl;
    
    cout << sln.minWindow("ADOBECODEBANC", "ABCC") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
