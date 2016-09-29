#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        // a is the minimum number so far
        // b is the minimum number so that there is some a before b, with a < b
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a > nums[i]) {
                a = nums[i];
            } else if (nums[i] > a && b > nums[i]) {
                b = nums[i];
            } else if (nums[i] > b) {
                return true;
            }
        }
        return false;
    }
};


void Test0()
{
    Solution sln;
    vector<int> nums = {1,5,5,5,5};
    cout << sln.increasingTriplet(nums) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
