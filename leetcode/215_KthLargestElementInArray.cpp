#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Comparator {
    bool operator()(int e1, int e2)
    {
        return e1 > e2;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int i;
        priority_queue<int, vector<int>, Comparator> Q;
       
        for (i = 0; i < k; ++i)
        {
            Q.push(nums[i]);
        }
        
        for (i = k; i < n; ++i)
        {
            if (Q.top() < nums[i])
            {
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
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


int main()
{
    Solution sln;
    return 0;
}
