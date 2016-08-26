#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = (int)s.length();
        int opens[3] = {'(', '[', '{'};
        int closes[3] = {')', ']', '}'};
        
        vector<char> S;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (opens[j] == s[i]){
                    S.push_back(s[i]);
                } else if (closes[j] == s[i]) {
                    if (S.empty())
                        return false;
                    
                    char c = S.back();
                    S.pop_back();
                    
                    if (c != opens[j])
                        return false;
                }
            }
        }
        
        return S.empty();
    }
};

void Test0()
{
    Solution sln;
    printf("%d\n", sln.isValid("()[{}]"));
    printf("%d\n", sln.isValid("([)]"));
    printf("%d\n", sln.isValid("([]){}[]"));
    printf("%d\n", sln.isValid("([)]"));
}

int main()
{
    Test0();
    
    return 0;
}
