#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        int wordLen = (int) beginWord.length();
        int n = (int) wordList.size();
        vector<string> words(n);
        vector<vector<int>> adj(n);
        int i = 0;
        map<string, int> wordToIndex;
        for (string s : wordList) {
            words[i] = s;
            wordToIndex[s] = i++;
        }
        
        int start = -1, end = -1;
        for (int i = 0; i < n; ++i) {
            if (words[i] == beginWord) start = i;
            if (words[i] == endWord) end = i;
            
            string s = words[i];
            for (int j = 0; j < wordLen; ++j) {
                char old = s[j];
                for (int k = 0; k < 26; ++k) {
                    
                    s[j] = 'a' + k;
                    if (s[j] != old && wordToIndex.count(s)) {
                        int nb = wordToIndex[s];
                        if (nb > i) {
                            adj[i].push_back(nb);
                            adj[nb].push_back(i);
                        }
                    }
                    
                }
                s[j] = old;
            }
        }
        
        vector<vector<string>> ans;
        vector<int> dis(n, n);
        vector<bool> visited(n);
        int len = -1;
        
        queue<int> Q;
        dis[start] = 0;
        visited[start] = true;
        Q.push(start);
        
        while (!Q.empty()) {
            int idx = Q.front();
            Q.pop();
            
            for (int j : adj[idx]) {
                if (visited[j]) continue;
                visited[j] = true;
                dis[j] = min(dis[j], dis[idx] + 1);
                Q.push(j);
            }
        }
        
        if (dis[end] == n) return ans;
        
        vector<string> path;
        path.push_back(beginWord);
        findPaths(ans, words, dis, adj, start, end, path);
        
        return ans;
    }
    
private:
    void findPaths(vector<vector<string>> &ans, const vector<string> &words,
                   const vector<int>& dis, const vector<vector<int>>& adj, int i, int end, vector<string>& p) {
        if (i == end) {
            ans.push_back(p);
            return;
        }
        
        for (int j:adj[i]) {
            if (dis[j] == dis[i] + 1) {
                p.push_back(words[j]);
                findPaths(ans, words, dis, adj, j, end, p);
                p.pop_back();
            }
        }
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
template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
 
    unordered_set<string> ws = {"hot","dot","dog","lot","log"};
    printBoard (sln.findLadders("hit", "cog", ws));
}

int main()
{
    Test0();
    
    return 0;
}
