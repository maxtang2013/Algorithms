#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s == 0) return 0;
        
        int n = (int)nums.size();
        int i = 0, j = 0;
        long long sum = 0;
        int minLen = n + 1;
        
        while (i < n || sum >= s) {
            if (sum >= s) {
                // At this point, sum is the sum of range [j, ..., i)
                if (minLen > i-j) {
                    minLen = i-j;
                }
                sum -= nums[j++];
            } else {
                sum += nums[i++];
            }
        }
        if (minLen > n) minLen = 0;
        return minLen;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sln.minSubArrayLen(7, nums) << endl;
}

void Test1()
{
    Solution sln;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sln.minSubArrayLen(4, nums) << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
