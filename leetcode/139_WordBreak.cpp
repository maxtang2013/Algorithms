#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<int> wordLens;
        for (string str : wordDict) {
            wordLens.insert((int)str.length());
        }
        
        vector<int> lens(wordLens.size());
        int i = 0;
        for (int l : wordLens) {
            if (l == 0) continue;
            lens[i++] = l;
        }
        sort (lens.begin(), lens.end());
        
        int n = (int) s.length();
        int m = (int) lens.size();
        vector<bool> canBreak(n+1, 0);
        canBreak[0] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (lens[i] > j) break;
                if (canBreak[j-lens[i]]) {
                    if (wordDict.count(s.substr(j-lens[i], lens[i])) > 0) {
                        canBreak[j] = true;
                        break;
                    }
                }
            }
        }
        return canBreak[n];
    }
};

void Test0()
{
    Solution sln;
    unordered_set<string> dict = {"leet", "code"};
    cout << sln.wordBreak("leetleetcode", dict) << endl;
}

void Test1()
{
    Solution sln;
    unordered_set<string> dict = {"leet", "code"};
    cout << sln.wordBreak("leetleetcod3e", dict) << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
