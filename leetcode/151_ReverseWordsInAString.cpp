#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int n = (int) s.length();
        int i = 0, j = n-1, k;
        
        while (i < j) swap(s[i++], s[j--]);
        
        i = 0;
        while ( i < n ) {
            while (i < n && isspace(s[i])) ++i;
            j = i;
            while (i < n && !isspace(s[i])) ++i;
            k = i - 1;
            
            while (j < k) swap(s[j++], s[k--]);
        }
        
        i = 0;
        j = 0;
        while (i < n) {
            if ( (i==0 && isspace(s[0]))
                || (i > 0 && isspace(s[i]) && isspace(s[i-1]))) {
                ++i;
                continue;
            }
            
            s[j++] = s[i++];
        }
        while (j > 0 && isspace(s[j-1])) --j;
        
        s.erase(j, n-j);
    }
};

void Test0()
{
    Solution sln;
    string s = " This is   a   sentence.   ";
    sln.reverseWords(s);
    cout << s << endl;
    
    string s1 = "a";
    sln.reverseWords(s1);
    cout << s1 << endl;
}

int main()
{
    Test0();
    
    return 0;
}
