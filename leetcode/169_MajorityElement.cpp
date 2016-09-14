#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        int major = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == major) ++cnt;
            else if (cnt == 0) {
                major = nums[i];
                cnt = 1;
            } else {
                --cnt;
            }
        }
        return major;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {1, 2, 3,1,1,1,1,4,5};
    cout << sln.majorityElement(nums) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
