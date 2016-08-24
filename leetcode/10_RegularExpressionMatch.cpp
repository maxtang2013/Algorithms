#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

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
    bool isMatch(string s, string p) {
        
        if (p.empty())
            return s.empty();
        
        int m = (int)s.length(), n = (int)p.length();
        
        vector<vector<bool> > matches(n+1);
        
        for (int i = 0; i <= n; ++i) {
            matches[i].assign(m+1, false);
        }
        
        matches[0][0] = true;
        for (int i = 0; i < n; ) {
            
            if (p[i] == '*')
                return false;
            
            if (i < n - 1 && p[i+1] == '*') {
                for (int j = 0; j <= m; ++j) {
                    
                    matches[i+2][j] = matches[i][j];
                    
                    if (j > 0 && (p[i] == '.' || p[i] == s[j-1]) && matches[i+2][j-1]) {
                        matches[i+2][j] = true;
                    }
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    if (p[i] == '.' || p[i] == s[j]) {
                        matches[i+1][j+1] = matches[i][j];
                    }
                }
            }
            
            while (i < n && p[++i] == '*');
        }
        bool ans = matches[n][m];
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
}

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
     printf("%d\n", sln.isMatch("",""));
    
    printf("%d\n", sln.isMatch("aa","a"));
    printf("%d\n", sln.isMatch("aaa","aa"));
    printf("%d\n", sln.isMatch("aaa", "aaa"));
    printf("%s\n", sln.isMatch("aa","a*") ? "true" : "false");
    printf("%d\n", sln.isMatch("aa",".*"));
    printf("%d\n", sln.isMatch("aabad3","a*.*"));
    printf("%d\n", sln.isMatch("abbab", "a*b*a"));
}

int main()
{
    Test0();
    
    return 0;
}
