#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int len = 0;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == val) {
                if (j == -1) j = i;
            } else {
                if (j > -1) {
                    nums[j++] = nums[i];
                }
                ++len;
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
    vector<int> nums = {3,2,2,3};
    
    printf("%d\n", sln.removeElement(nums, 3));
    printVector(nums);
}

int main()
{
    Test0();
    
    return 0;
}
