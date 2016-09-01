#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        bool find = false;
        for (int i = n-1; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                
                int j = i;
                while (j < n && nums[j] > nums[i-1]) ++j;
                
                swap(nums[i-1], nums[j-1]);
                
                j = n-1;
                while (i < j) {
                    swap(nums[i], nums[j]);
                    ++i;
                    --j;
                }
                find = true;
                break;
            }
        }
        if (!find) {
            int i = 0, j = n-1;
            while (i < j) {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
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

void Test0()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < 20; ++i) {
        sln.nextPermutation(nums);
        printVector(nums);
    }
}

int main()
{
    Test0();
    
    return 0;
}
