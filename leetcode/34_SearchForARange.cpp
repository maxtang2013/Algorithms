#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, hi = (int) nums.size();
        
        while (low < hi) {
            int mid = (low + hi) / 2;
            if (nums[mid] >= target) {
                hi = mid;
            } else {
                low = mid + 1;
            }
        }
        
        int lower = low;
        if (lower == nums.size() || nums[lower] < target)
            ++lower;
            
        low = 0;
        hi = (int) nums.size();
        while (low < hi) {
            int mid = (low + hi) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        int upper = low;
        if (upper == nums.size() || nums[upper] > target) --upper;
        
        if (upper < lower) {
            upper = lower = -1;
        }
        
        vector<int> ans;
        ans.push_back(lower);
        ans.push_back(upper);
        return ans;
    }
};
template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}


void Test0()
{
    Solution sln;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    printVector (sln.searchRange(nums, 8));
}

int main()
{
    Test0();
    
    return 0;
}
