#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        if (nums.size() == 1) return nums[0];
        
        int n = (int) nums.size();
        int lo = 0, hi = n - 1;
        
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            
            if (nums[mid] > nums[0]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[0]) {
                hi = mid;
            } else if (nums[hi] < nums[hi-1]){
                return nums[hi];
            } else {
                --hi;
            }
        }
        
        if (hi == n - 1 && nums[hi] >= nums[hi-1])
            return nums[0];
        
        return nums[hi];
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {4, 5, 6, 1, 2, 4,4,4,4,4,4,4,4};
    cout << sln.findMin(nums) << endl;
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1, 2, 4,4,4,4,4,4,4,4};
    cout << sln.findMin(nums) << endl;
}
void Test2()
{
    Solution sln;
    vector<int> nums = {3, 5, 1};
    cout << sln.findMin(nums) << endl;
}

void Test3()
{
    Solution sln;
    vector<int> nums = {3, 1};
    cout << sln.findMin(nums) << endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
