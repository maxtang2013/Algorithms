#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>

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

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, hi = 46341;
        
        while (low < hi) {
            int mid = (low + hi) / 2;
            if (mid * mid > num) {
                hi = mid - 1;
            } else if ( mid * mid == num ){
                return true;
            } else {
                low = mid + 1;
            }
        }
        
        if (low * low == num || (low - 1) * (low - 1) == num)
            return true;
        
        return false;
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
    printf("%d\n", sln.isPerfectSquare(2147395600));
}

int main()
{
    Test0();
    cout << 46340 * 46340 << endl;
    cout << sqrt(INT_MAX) << endl;
    
    return 0;
}
