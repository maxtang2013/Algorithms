#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return nums;
        int n = (int) nums.size();
        vector<int> ans;
        deque<int> Q;
        
        for (int i = 0; i < n; ++i) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) {
                Q.pop_back();
            }
            
            Q.push_back(i);
            
            if (Q.front() + k <= i) Q.pop_front();
            
            if (i >= k - 1) {
                ans.push_back(nums[Q.front()]);
            }
        }
        
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
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    printVector(sln.maxSlidingWindow(nums, 3));
}

int main()
{
    Test0();
    
    return 0;
}
