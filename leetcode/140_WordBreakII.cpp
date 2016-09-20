#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<int> wordLens;
        for (string str : wordDict) {
            wordLens.insert((int)str.length());
        }
        mWordDict = wordDict;
        
        vector<int> lens(wordLens.size());
        int i = 0;
        for (int l : wordLens) {
            if (l == 0) continue;
            lens[i++] = l;
        }
        sort (lens.begin(), lens.end());
        
        
        int n = (int) s.length();
        mNumLens = (int) lens.size();
        vector<bool> canBreak(n+1, 0);
        canBreak[0] = 1;
        for (i = 1; i <= n; ++i) {
            for (int j = 0; j < mNumLens; ++j) {
                if (lens[j] > i) break;
                if (canBreak[i-lens[j]]) {
                    if (wordDict.count(s.substr(i-lens[j], lens[j])) > 0) {
                        canBreak[i] = true;
                        break;
                    }
                }
            }
        }
        if (canBreak[n])
        {
            // Back tracing
            getAllSentences(s, lens, canBreak, n, "");
        }
        return mSentences;
    }
    
    void getAllSentences(string &s, vector<int>& lens, const vector<bool> &canBreak, int k, const string& sentence) {
        if (k == 0) {
            mSentences.push_back(sentence);
            return;
        }
        for (int i = 0; i < mNumLens; ++i) {
            int l = lens[i];
            if (l > k) break;
            
            if (canBreak[k-l]) {
                string word = s.substr(k-l, l);
                if (mWordDict.count(word) > 0) {
                    string ss = sentence.empty() ? word : word + " " + sentence;
                    getAllSentences(s, lens, canBreak, k-l, ss);
                }
            }
        }
    }
private:
                
    unordered_set<string> mWordDict;
    int mNumLens;
    vector<string> mSentences;
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << endl;
        else std::cout << "\n";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    unordered_set<string> dict = {"leet", "lee", "t", "code"};
    printVector(sln.wordBreak("leetleetcode", dict));
}

void Test1()
{
    Solution sln;
    unordered_set<string> dict = {"leet", "code"};
    printVector(sln.wordBreak("leetleetcod3e", dict));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
