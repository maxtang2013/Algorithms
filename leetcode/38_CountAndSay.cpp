#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        string x = "1";
        
        int k = 1;
        for (k = 2; k <= n; ++k) {
            string y;
            int i = 1;
            int len = (int) x.length();
            int num = 1;
            while (i < len) {
                if (x[i] != x[i-1]) {
                    y.append(1, (char)('0' + num));
                    y.append(1, x[i-1]);
                    num = 1;
                } else {
                    ++num;
                }
                ++i;
            }
            y.append(1, (char)('0' + num));
            y.append(1, x[i-1]);
            
            x = y;
        }
        return x;
    }
};

void Test0()
{
    Solution sln;
    
    for (int i = 2; i < 30; ++i) {
        cout << sln.countAndSay(i) << endl << endl;
    }
}

int main()
{
    Test0();
    
    return 0;
}
