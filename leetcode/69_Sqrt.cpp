#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        long long hi = x + (long long)1, lo = 0;
        
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            
            if (mid * mid == x) return (int)mid;
            
            if (mid * mid > x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (lo * lo > x) --lo;
        return lo;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.mySqrt(16) << endl;
    cout << sln.mySqrt(101) << endl;
    cout << sln.mySqrt(99) << endl;
    
    cout << sln.mySqrt(1) << endl;
    
    cout << sln.mySqrt(0) << endl;
    
    cout << sln.mySqrt(2147395599) << endl;
    
    cout << sln.mySqrt(2147483647) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
