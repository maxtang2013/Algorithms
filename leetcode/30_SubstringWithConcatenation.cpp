#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        
        int n = words.size();
        int wordLen = words[0].length();
        unordered_map<string, int> wordsMap;
        for (int i = 0; i < words.size(); ++i) {
            if (wordsMap.count(words[i]) == 0)
                wordsMap[words[i]] = 1;
            else
                ++wordsMap[words[i]];
        }
        
        int len = s.length();
        for (int i = 0; i <= len-wordLen; ++i) {
            unordered_map<string, int> wordMap;
            int j = 0;
            for (j = 0; j < n; ++j) {
                wordMap[words[j]] = 0;
            }
            
            for (j = 0; j < n; ++j) {
                string sub = s.substr(i + j*wordLen, wordLen);
                if (wordsMap.count(sub) == 1 && wordMap[sub] < wordsMap[sub]) {
                    ++wordMap[sub];
                } else {
                    break;
                }
            }
            if (j == n) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<string> words = {"foo", "bar"};
    printVector(sln.findSubstring("barfoothefoobarman", words));
}


void Test1()
{
    Solution sln;
    vector<string> words = {"word","good","best","good"};
    printVector(sln.findSubstring("wordgoodgoodgoodbestword", words));
}
void Test2()
{
    Solution sln;
    vector<string> words = {"a"};
    printVector(sln.findSubstring("a", words));
}
int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
