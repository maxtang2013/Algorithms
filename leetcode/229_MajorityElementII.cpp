#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
class Solution {
public:
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if (nums.size() < 2) return nums;
        vector<int> ans;
        int first = 0, second = 0;
        int cnt1 = 0, cnt2 = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            if (v == first) {
                ++cnt1;
            } else if (v == second) {
                ++cnt2;
            }else if (cnt1 == 0) {
                first = v;
                cnt1=1;
            } else if (cnt2 == 0) {
                second = v;
                cnt2=1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        
        cnt1 = cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first == nums[i]) {
                ++cnt1;
            } else if (second == nums[i]) {
                ++cnt2;
            }
        }
        if (cnt1 > nums.size() / 3) ans.push_back(first);
        if (cnt2 > nums.size() / 3) ans.push_back(second);
        
        return ans;
    }
};

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
