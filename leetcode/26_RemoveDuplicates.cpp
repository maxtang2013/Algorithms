#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) return n;
        
        int i = 0;
        int len = 1;
        int j = -1;
        for (i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                ++len;
                if (j > -1) {
                    nums[j] = nums[i];
                    ++j;
                }
            } else {
                if (j == -1)
                    j = i;
            }
        }
        return len;
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
    vector<int> nums = {1, 1, 2, 3, 4, 4, 5, 5, 5, 5, 6, 7, 7, 7,7};
    printf("%d\n", sln.removeDuplicates(nums));
    
    printVector(nums);
}

int main()
{
    Test0();
    
    return 0;
}
