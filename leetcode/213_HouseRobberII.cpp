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

class Solution {
public:
    int rob(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int max0 = 0, max1 = nums[1];
        int m1;
        for (int i = 2; i < n; ++i)
        {
            int maxcnt = max(max0 + nums[i], max1);
            max0 = max1;
            max1 = maxcnt;
        }
        
        m1 = max1;
        max0 = 0, max1 = nums[0];
        for (int i = 1; i < n - 1; ++i)
        {
            int maxcnt = max(max0 + nums[i], max1);
            max0 = max1;
            max1 = maxcnt;
        }
        
        m1 = max(m1, max1);
        
        return m1;
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
}

int main()
{
    Test0();
    
    return 0;
}
