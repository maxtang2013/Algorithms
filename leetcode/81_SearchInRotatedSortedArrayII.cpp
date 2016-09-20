#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int n = nums.size();
        
        int arrayStartIndex = -1;
        // Find the start index
        int low = 0, hi = n;
        int n0 = nums[0];
        while (low < hi) {
            int mid = low + (hi - low) / 2;
            if (nums[mid] > n0) {
                low = mid + 1;
            } else if (nums[mid] < n0) {
                hi = mid;
            } else if (hi < n && nums[hi] < nums[hi-1]) {
                arrayStartIndex = hi;
                break;
            } else {
                --hi;
            }
        }
        if (hi == 0) hi = n;
        
        arrayStartIndex = hi;
        
        if (target < n0) {
            low = arrayStartIndex;
            hi = n;
        } else if (target > n0) {
            low = 0;
            hi = arrayStartIndex;
        } else return true;
        
        while (low < hi) {
            // (low + hi) / 2 may overflow.
            int mid = low + (hi - low) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                hi = mid;
        }
        return false;
    }
};

void Test0()
{
    Solution sln;
    
    vector<int> nums = {1,1,4,5,6,1,1,1,1,1};
    cout << sln.search(nums, 3) << endl;
    cout << sln.search(nums, 1) << endl;
    cout << sln.search(nums, 6) << endl;
}

void Test1()
{
    Solution sln;
    
    vector<int> nums = {4,5,6,1,1,1,2,2};
    cout << sln.search(nums, 3) << endl;
    cout << sln.search(nums, 2) << endl;
    cout << sln.search(nums, 6) << endl;
}

void Test2()
{
    Solution sln;
    
    vector<int> nums = {1,1,3};
    cout << sln.search(nums, 3) << endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
