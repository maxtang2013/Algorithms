#include <iostream>
#include <vector>

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
    
    return 0;
}
