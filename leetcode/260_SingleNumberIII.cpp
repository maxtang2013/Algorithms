#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bits = 0;
        int i, n = nums.size();
        unsigned int mask = 1;
        int num1 = 0, num2 = 0;
        
        
        for (i = 0; i < n; ++i) bits ^= nums[i];
        
        for (i = 0; i < 32; ++i)
        {
            if (bits & mask)
            {
                break;
            }
            mask = mask << 1;
        }
        
        for (i = 0; i < n; ++i)
        {
            if (nums[i] & mask)
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
    
    
    vector<int> singleNumber2(vector<int>& nums)
    {
        // Pass 1 :
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;
        
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
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
//    for (i = 0; i < 32; ++i)
//    {
//        if (bits & mask)
//        {
//            break;
//        }
//        mask = mask << 1;
//    }
    
    return n & (-n);
}

void printBits(int n)
{
    for (int i = 31; i >= 0; --i)
    {
        if (n & (1<<i)) std::cout << "1";
        else std::cout << "0";
    }
    std::cout << "\n";
}

int main()
{
    Solution sln;
    
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    
    printVector<int>(sln.singleNumber(nums));
    
    printf("%d\n", 1&(-1));
    printf("%d\n", 2&(-2));
    printf("%d\n", 3&(-3));
    printf("%d\n", 4&(-4));
    
    printBits(-1);
    printBits(-3);
    
    int x = 1 << 30;
    bitset<32> bits(x);
    std::cout << bits << std::endl;
    x = x << 1;
    std::cout << x << std::endl;
    std::cout << bitset<32>(x) << std::endl;
    
    return 0;
}
