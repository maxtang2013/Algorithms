#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        
        long long ans = 0;
        long long p = 1;
        int sign = 1;
        
        long long dend = dividend;
        long long dsor = divisor;
        
        if (dend < 0) {
            sign *= -1;
            dend = -dend;
        }
        
        if (dsor < 0) {
            sign *= -1;
            dsor = -dsor;
        }
        
        if (dend < dsor) return 0;
        
        long long mul = dsor;
        
        while (mul <= dend) {
            mul = mul << 1;
            p = p << 1;
        }
        
        mul = mul >> 1;
        p = p >> 1;
        
        while (mul >= dsor) {
            if (mul <= dend) {
                dend -= mul;
                ans += p;
            }
            mul = mul >> 1;
            p = p >> 1;
        }
        
        if (ans > INT_MAX) {
            ans = INT_MAX;
        }
        
        return sign*(int)ans;
    }
};

void Test0()
{
    Solution sln;
    
    printf("%d\n", sln.divide(185, 5));
    printf("%d\n", sln.divide(185, -5));
    printf("%d\n", sln.divide(-2147483648, -1));//, <#int divisor#>))
}

int main()
{
    Test0();
    
    return 0;
}
