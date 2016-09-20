#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 0;
        if (n == 2) return nums[0] > nums[1] ? 0 : 1;
        
        int lo = 0, hi = n - 1;
        
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            bool left = false, right = false;
            if (mid == 0 || nums[mid-1] < nums[mid]) left = true;
            if (nums[mid] > nums[mid+1]) right = true;
            
            if (left && right) return mid;
            
            if (left) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 1};
    cout << sln.findPeakElement(nums) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
