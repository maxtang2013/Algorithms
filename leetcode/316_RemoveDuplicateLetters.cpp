#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;


// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.
// You must make sure your result is the smallest in lexicographical order among all possible results.
//
// Example:
// Given "bcabc"
// Return "abc"
//
// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> Stack;
        vector<int> cnt(26);
        vector<int> visited(26);
        
        for (char c: s) cnt[c-'a']++;
        
        for (char c: s) {
            cnt[c-'a']--;
            if (visited[c-'a']) continue;
            
            while (!Stack.empty() && Stack.back() > c && cnt[Stack.back()-'a'] > 0) {
                visited[Stack.back()-'a'] = false;
                Stack.pop_back();
            }
            visited[c-'a'] = true;
            Stack.push_back(c);
        }
        
        string ans = "";
        for (char c:Stack) ans.append(1, c);
        return ans;
    }
    string removeDuplicateLetters_mine(string s) {
        int n = (int) s.length();
        vector<int> nextPosition[26];
        
        string ans = "";
        int mask = 0;
        for (int i = 0; i < n; ++i)
            mask |= (1<<(s[i]-'a'));
        
        for (int j = 0; j < 26; ++j) {
            nextPosition[j].resize(n+1, -1);
            for (int i = n-1; i >= 0; --i) {
                if (s[i] == 'a' + j) {
                    nextPosition[j][i] = i;
                } else {
                    nextPosition[j][i] = nextPosition[j][i+1];
                }
            }
        }
        
        unordered_map<int, int> powToIndex;
        for (int i = 0; i < 26; ++i) {
            powToIndex[1<<i] = i;
        }
        
        int start = 0;
        while (mask > 0 && start < n) {
            
            int t=mask;
            while (t > 0) {
                int i = powToIndex[t & (-t)];
                int k = nextPosition[i][start];
                int inner_t = mask;
                bool notEnough = false;
                
                while (inner_t > 0) {
                    int j = powToIndex[inner_t & (-inner_t)];
                    if (j != i && nextPosition[j][k] < k) {
                        notEnough = true;
                        break;
                    }
                    inner_t = inner_t & (inner_t - 1);
                }
                
                if (!notEnough) {
                    mask = mask ^ (1<<i);
                    ans.append(1, 'a' + i);
                    start = k+1;
                    break;
                }
                
                t = t & (t - 1);
            }
        }
        return ans;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.removeDuplicateLetters("cbacdcbc") << endl;
    cout << sln.removeDuplicateLetters("bbcaac") <<endl;
}

int main()
{
    Test0();
    
    return 0;
}
