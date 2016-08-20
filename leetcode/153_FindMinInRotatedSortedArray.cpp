#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (nums[n-1] > nums[0]) return nums[0];
        
        int lower = 0, upper = n - 1;
        while (lower < upper)
        {
            int mid = (lower + upper) / 2;
            
            if (nums[mid] >= nums[0])
            {
                lower = mid + 1;
            }
            else
            {
                upper = mid - 1;
            }
        }
        
        return nums[lower] >= nums[0] ? nums[lower+1] : nums[lower];
    }
};
void Test0()
{
    Solution sln;
    
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", sln.findMin(nums));
    
    
}

void Test1()
{
    Solution sln;
    
    vector<int> nums = {4, 3};
    printf("%d\n", sln.findMin(nums));
    
    
}
void Test2()
{
    Solution sln;
    
    vector<int> nums = {4, 6, 7, 0, 1, 2};
    printf("%d\n", sln.findMin(nums));
    
    
}
void Test3()
{
    Solution sln;
    
    vector<int> nums = {4, 6, 0, 1, 2};
    printf("%d\n", sln.findMin(nums));
    
    
}

void Test4()
{
    Solution sln;
    
    vector<int> nums = {4, 6, 0, 2};
    printf("%d\n", sln.findMin(nums));
    
    
}

void Test5()
{
    Solution sln;
    
    vector<int> nums = {1, 3};
    printf("%d\n", sln.findMin(nums));
    
    
}


int main()
{
    // Test0();
//    Test1();
//    Test2();
//    Test3();
//    Test4();
    Test5();
    
    return 0;
}
