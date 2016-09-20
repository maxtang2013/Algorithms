#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>


using namespace std;

struct Entry {
    int index;
    int dis;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.dis > e2.dis;
    }
};



class Solution {
    struct Item {
        string s;
        int dis;
    };
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<Item> Q;
        int strLen = (int) beginWord.length();
        Item item = {beginWord, 1};
        Q.push(item);
        wordList.insert(endWord);
        while (!Q.empty()) {
            item = Q.front();
            Q.pop();
            
            string s = item.s;
            
            if (s == endWord)
                return item.dis;
            
            for (int i = 0; i < strLen; ++i) {
                char old = s[i];
                for (int t = 0; t < 26; ++t) {
                    char c = t + 'a';
                    if (c == old) continue;
                    
                    s[i] = c;
                    
                    unordered_set<string>::iterator it = wordList.find(s);
                    if (it != wordList.end()) {
                        Item ni = {s, item.dis+1};
                        Q.push(ni);
                        wordList.erase(it);
                    }
                }
                s[i] = old;
            }
        }
        return 0;
    }
    
    int ladderLength_1(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        int wordLen = beginWord.length();
        int n = wordList.size();
        vector<string> words(n);
        vector<vector<int>> adj(n);
        int i = 0;
        for (string s : wordList) {
            words[i++] = s;
        }
        int start = -1, end = -1;
        for (int i = 0; i < n; ++i) {
            if (words[i] == beginWord) start = i;
            if (words[i] == endWord) end = i;
            
            for (int j = i + 1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < wordLen; ++k) {
                    if (words[i][k] != words[j][k] && ++diff > 1) break;
                }
                if (diff == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n);
        int ans = -1;
        priority_queue<Entry, vector<Entry>, Comparator> Q;
        Entry e = {start, 0};
        visited[start] = true;
        Q.push(e);
        while (!Q.empty()) {
            e = Q.top();
            Q.pop();
            
            if (e.index == end) {
                ans = e.dis;
                break;
            }
            for (int j : adj[e.index]) {
                if (visited[j]) continue;
                visited[j] = true;
                Entry ne = {j, e.dis + 1};
                Q.push(ne);
            }
        }
        return ans + 1;
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
    cout << sln.ladderLength("hit", "cog", ws) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
