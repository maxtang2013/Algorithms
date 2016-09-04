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
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int diff = 0, prev = 0, ans = 0;
        int n = (int) nums.size(), i;
        
        if (n < 2) return n;
        
        ans = 1;
        
        for (i = 1; i < n; ++i)
        {
            diff = nums[i] - nums[i - 1];
            if (diff != 0 && ans < 2) ans = 2;
            if (sgn(prev) * sgn(diff) < 0) ++ans;
            
            if (diff != 0) prev = diff;
        }
        
        return ans;
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
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    Solution sln;
    printf("%d\n", sln.wiggleMaxLength(nums));
}

void Test1()
{
    vector<int> nums = {1};
    Solution sln;
    printf("%d\n", sln.wiggleMaxLength(nums));
}

void Test2()
{
    vector<int> nums = {1, 1};
    Solution sln;
    printf("%d\n", sln.wiggleMaxLength(nums));
}

void Test3()
{
    vector<int> nums = {1,7,4,9,2,5};
    Solution sln;
    printf("%d\n", sln.wiggleMaxLength(nums));
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
