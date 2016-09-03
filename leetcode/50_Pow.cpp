#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double p = x;
        long long mask = 1;
        double sign = 1;
        long long exp = n;
        
        if (x == 0) return 0;
        
        if (exp < 0) {
            exp = -exp;
            sign = -1;
        }
        
        while (mask <= exp) {
            if (exp & mask) ans *= p;
            p *= p;
            mask = mask << 1;
        }
        if (sign == -1)
            ans = 1 / ans;
        return ans;
    }
};

void Test0()
{
    Solution sln;
    printf("%lf\n", sln.myPow(1.1, 13));
    
    printf("%lf\n", sln.myPow(2.0, INT_MIN));
    
    
    printf("%lf\n", sln.myPow(34.00515, -3));
}

int main()
{
    Test0();
    
    return 0;
}
