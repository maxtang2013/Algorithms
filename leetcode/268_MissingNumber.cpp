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
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        
        long long expected = n * (long long) (n + 1) / 2;
        return (int)(expected - sum);
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
    vector<int> nums = {0, 1, 3};
    printf("%d\n", sln.missingNumber(nums));
}

int main()
{
    Test0();
    
    return 0;
}
