#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int carry = 0;
        int i = n - 1, j = m - 1;
        string ans;
        
        
        while (i >= 0 && j >= 0) {
            int d = (a[i] - '0') + (b[j] - '0')  + carry;
            if (d > 1) {
                d -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.append(1, d + '0');
            --i;
            --j;
        }
        
        while (i >= 0) {
            int d = a[i] - '0' + carry;
            if (d > 1) {
                d -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            
            ans.append(1, d + '0');
            --i;
        }
        while (j >= 0) {
            int d = b[j] - '0' + carry;
            if (d > 1) {
                d -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.append(1, d + '0');
            --j;
        }
        
        if (carry > 0) ans.append(1, '1');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


void Test0()
{
    Solution sln;
    
    // cout << sln.addBinary("100101111", "111001111") << endl;
    
    cout << sln.addBinary("11", "1") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
