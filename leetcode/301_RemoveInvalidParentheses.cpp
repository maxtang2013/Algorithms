#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, ans, 0, 0, "()");
        return ans;
    }
    
private:
    void remove(string s, vector<string> &ans, int last_i, int last_j, const string &par) {
        int len = (int) s.length();
        for (int stack = 0, i = last_i; i < len; ++i) {
            
            if (s[i] == par[0]) ++stack;
            if (s[i] == par[1]) --stack;
            
            if (stack >= 0) continue;
            
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == par[1] && (j == last_j || s[j-1] != par[1]))
                    remove(s.substr(0, j) + s.substr(j+1), ans, i, j, par);
            }
            return;
        }
        
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (par[0] == '(')
            remove(rev, ans, 0, 0, ")(");
        else
            ans.push_back(rev);
    }
    
    vector<string> removeInvalidParentheses1(string s) {
        vector<string> ans;
        
        int l = 0, n = (int) s.length();
        int i;
        
        if (n == 0) {
            ans.push_back("");
            return ans;
        }
        
        // Skip other characters
        i = 0;
        while (i < n && s[i] != ')' && s[i] != '(') ++i;
        
        if (i > 0) {
            string prefix = s.substr(0, i);
            vector<string>list = removeInvalidParentheses(s.substr(i));
            for (string ss: list) ans.push_back(prefix+ss);
            goto DONE;
        }
        
        for (i = 0; i < n; ++i) {
            if (s[i] == '(') ++l;
            else if (s[i] == ')') --l;
            
            if (l <= 0) {
                while (i < n && s[i] != '(') ++i;
                break;
            }
        }
        
        if (l == 0) {
            string prefix = s.substr(0, i);
            vector<string>list = removeInvalidParentheses(s.substr(i));
            for (string ss: list) ans.push_back(prefix+ss);
        } else if (l < 0) {
            vector<string> list = removeInvalidRightParentheses(s.substr(0, i), l);
            vector<string> list2 = removeInvalidParentheses(s.substr(i));
            for (string s1: list) {
                for (string s2 : list2) {
                    ans.push_back(s1 + s2);
                }
            }
        } else {
            vector<string> list = removeInvalidLeftParentheses(s.substr(0, i), l);
            vector<string> list2 = removeInvalidParentheses(s.substr(i));
            for (string s1: list) {
                for (string s2 : list2) {
                    ans.push_back(s1 + s2);
                }
            }
        }
        
    DONE:
        ans = removeDuplicate(ans);
        return ans;
    }
    
private:
    vector<string> removeDuplicate(vector<string> &list)
    {
        if (list.empty()) return list;
        
        vector<string> res;
        int n = list.size();
        
        res.reserve(n);
        
        sort(list.begin(), list.end());
        
        res.push_back(list[0]);
        for (int i=1; i < n; ++i) {
            if (list[i] == list[i-1]) continue;
            res.push_back(list[i]);
        }
        return res;
    }
    
    vector<string>  join(vector<string> list1,vector<string> list2)
    {
        vector<string> res;
        res.reserve(list1.size() * list2.size());
        
        for (string s1:list1) {
            for (string s2:list2) {
                res.push_back(s1+s2);
            }
        }
        return res;
    }
    
public:
    vector<string> removeInvalidLeftParentheses(string s, int l) {
        vector<string> ans;
        int n = s.length();
        vector<int> leftToRemove(n, 0);
        
        // ((()())((())
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                for (int j = 0; j < i; ++j) {
                    if (s[j] == '(') {
                        --l;
                        if (l >= 0)
                        {
                            string s1 = s.substr(0, j);
                            string s2 = s.substr(j+1, i-j-1);
                            string s3 = s.substr(i+1);
                            
                            vector<string>list1 = removeInvalidParentheses(s1);
                            vector<string> list12; list12.push_back("(");
                            vector<string>list2 = removeInvalidParentheses(s2);
                            vector<string>list3;
                            list3.push_back(")");
                            vector<string> list4 = removeInvalidParentheses(s3);
                            
                            vector<string> list = join(join(join(join(list1, list12), list2), list3), list4);
                            ans.insert(ans.end(), list.begin(), list.end());
                        } else break;
                        
                        // skip
                        while (++j < i && s[j] == '(') --l;
                        
                    } else if (s[j] == ')') ++l;
                }
                break;
            }
        }
        
        if (ans.empty()) ans.push_back("");
        
        return ans;
    }
    
    vector<string> removeInvalidRightParentheses(string s, int l) {
        vector<string> ans;
        
        int n = s.length();
        int r = 0;
        
        for (int i = n-1; i > 0; --i) {
            if (s[i] == ')') {
                ++r;
                if (r + l <= 0) {
                    string s1 = s.substr(1, i-1);
                    string s2 = s.substr(i + 1);
                    
                    vector<string>list1; list1.push_back("(");
                    vector<string>list2 = removeInvalidParentheses(s1);
                    vector<string>list3; list3.push_back(")");
                    vector<string>list4 = removeInvalidParentheses(s2);
                    
                    vector<string> list = join(join(join(list1, list2), list3), list4);
                    ans.insert(ans.end(), list.begin(), list.end());
                }
                
                // skip
                while (--i > 0 && s[i] == '(') ++r;
            }
            else if (s[i] == '(') --r;
            
            if (r + l > 0) break;
        }
        
        if (ans.empty())
        {
            ans.push_back("");
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
    printf("\n");
}

void Test1()
{
    Solution sln;
    printVector(sln.removeInvalidLeftParentheses("(()(", 3));
    
    printVector(sln.removeInvalidRightParentheses("()()))", -2));
}

void Test0()
{
    Solution sln;
    printVector(sln.removeInvalidParentheses("()())()"));
    printVector(sln.removeInvalidParentheses(""));
    printVector(sln.removeInvalidParentheses("(a)())()"));
    printVector(sln.removeInvalidParentheses("()"));
}

int main()
{
    Test0();
    
    return 0;
}
