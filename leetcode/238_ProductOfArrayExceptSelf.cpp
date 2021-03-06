#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> ans(n, 1);
        int rightPart = 1;
        int i;
        
        ans[0] = 1;
        for (i = 1; i < n; ++i)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        for (i = n-1; i > 0; --i)
        {
            rightPart *= nums[i];
            ans[i-1] *= rightPart;
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


int main()
{
    Solution sln;
    vector<int> nums = {1, 0};
    printVector(sln.productExceptSelf(nums));
    return 0;
}
