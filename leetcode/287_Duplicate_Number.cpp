#include <vector>
using namespace std;

class Solution 
{
public:
    int findDuplicate(vector<int>& nums)
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
