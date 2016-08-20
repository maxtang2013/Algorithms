#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int lower = 0, upper = (int)nums.size() - 1;
        
        while (lower < upper)
        {
            int mid = (lower + upper)/2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < target)
            {
                lower = mid + 1;
            }
            else
            {
                upper = mid - 1;
            }
        }
        
        return target > nums[lower] ? lower + 1 : lower;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {0, 2};
    printf("%d\n", sln.searchInsert(nums, 1));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1,3,5,6};
    printf("%d\n", sln.searchInsert(nums, 1));
}

void Test2()
{
    Solution sln;
    vector<int> nums = {1,3};
    printf("%d\n", sln.searchInsert(nums, 4));
}

void Test3()
{
    Solution sln;
    vector<int> nums = {1};
    printf("%d\n", sln.searchInsert(nums, 4));
}

void Test4()
{
    Solution sln;
    vector<int> nums = {1};
    printf("%d\n", sln.searchInsert(nums, 0));
}

void Test5()
{
    Solution sln;
    vector<int> nums = {1,3};
    printf("%d\n", sln.searchInsert(nums, 0));
}

void Test6()
{
    Solution sln;
    vector<int> nums = {1};
    printf("%d\n", sln.searchInsert(nums, 1));
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    return 0;
}
