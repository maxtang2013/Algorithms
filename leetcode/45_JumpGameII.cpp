#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int) nums.size() - 1;
        if (n == 0) return 0;
        
        int low = 0, hi = nums[0];
        int ans = 1;
        
        while (hi < n) {
            int m = hi;
            for (int i = low+1; i <= hi; ++i) {
                m = max(nums[i] + i, m);
            }
            
            low = hi;
            hi = m;
            ++ans;
        }
        
        return ans;
    }
    
    int jump_DP_(vector<int>& nums) {
        vector<int> minSteps;
        int n = (int) nums.size();
        minSteps.resize(n, INT_MAX);
        minSteps[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int maxLen = nums[i];
            for (int j = i+1; j < n && j <= i + maxLen; ++j) {
                minSteps[j] = min(minSteps[j], minSteps[i] + 1);
            }
        }
        return minSteps[n-1];
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {2,3,1,1,4};
    printf("%d\n", sln.jump(nums));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1,1,1,1};
    printf("%d\n", sln.jump(nums));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
