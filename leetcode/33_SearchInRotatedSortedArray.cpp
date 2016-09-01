#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, hi = (int) nums.size();
        if (hi == 0) return -1;
        
        while (low < hi) {
            int mid = (low + hi) / 2;
            if (nums[mid] < nums[0]) {
                hi = mid;
            } else {
                low = mid + 1;
            }
        }
        
        if (low == nums.size() || nums[low] < nums[0]) {
            --low;
        }
        
        if (target >= nums[0]) {
            hi = low;
            low = 0;
        } else {
            hi = nums.size();
        }
        
        while (low < hi) {
            int mid = (low + hi) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (low < nums.size() && nums[low] == target)
            return low;
        return -1;
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
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    printf("%d\n", sln.search(nums, 5));
    
    printf("%d\n", sln.search(nums, 3));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {};
    printf("%d\n", sln.search(nums, 0));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
