#include <vector>
using namespace std;

//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
class Solution
{
public:
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int fast = 0, slow = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    
    int findDuplicate_binarySearch(vector<int>& nums)
    {                    
        int start = 1, end = nums.size() - 1;
        int mid;

        while (start < end)
        {
            mid = (start + end) / 2;
            if (testRange(nums, start, mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
private:
    bool testRange(const vector<int>& nums, int start, int end)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] >= start && nums[i] <= end)
                ++res;
        }
        return res > end - start + 1;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    
    Solution sln;
    printf("%d\n", sln.findDuplicate(nums));
}
