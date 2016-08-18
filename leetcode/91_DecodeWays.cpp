#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int cnt0 = 1, cnt1 = 1;
        int n = s.length();
        
        if (n == 0) return 0;
        
        for (int i= 0; i < n; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return 0;
            }
        }
        if (s[0] == '0') return 0;
        
        for (int i = 1; i < n; ++i)
        {
            int cnt = 0;
            if (s[i] > '0') cnt += cnt1;
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
            {
                cnt += cnt0;
            }
            cnt0 = cnt1;
            cnt1 = cnt;
        }
        return cnt1;
    }
};

void Test0()
{
    Solution sln;
    printf("%d\n", sln.numDecodings("12"));
}

void Test1()
{
    Solution sln;
    printf("%d\n", sln.numDecodings("1232143223457689124"));
}

void Test2()
{
    Solution sln;
    printf("%d\n", sln.numDecodings(""));
}

void Test3()
{
    Solution sln;
    printf("%d\n", sln.numDecodings("10"));
}

void Test4()
{
    Solution sln;
    printf("%d\n", sln.numDecodings("100111"));
}

int main()
{
    Test0();
//    Test1();
//    Test2();
//    Test3();
    Test4();
    
    return 0;
}
