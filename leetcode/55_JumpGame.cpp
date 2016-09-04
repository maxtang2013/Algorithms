#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = (int) nums.size() - 1;
        int i = target - 1;
        
        while (target > 0 && i >= 0) {
            if (nums[i] + i >= target) target = i;
            --i;
        }
        return target == 0;
    }
    
    bool canJump_RangeOut(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = nums[0];
        
        while (lo < n) {
            int m = hi;
            
            for (int i = lo; i < n && i <= hi; ++i) {
                m = max(m, i + nums[i]);
            }
            
            if (hi >= m) break;
            
            lo = hi + 1;
            hi = m;
        }
        
        return hi >= n - 1;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {2,3,1,1,4};
    printf("%d\n", sln.canJump(nums));
    
    vector<int> nums1 = {3,2,1,0,4};
    printf("%d\n", sln.canJump(nums1));
}

int main()
{
    Test0();
    
    return 0;
}
