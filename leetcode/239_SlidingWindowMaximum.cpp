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
        deque<pair<int,int>> Q;
        pair<int, int> p(-1, INT_MIN);
        
        Q.push_back(make_pair(0, nums[0]));
        if (k == 1) ans.push_back(nums[0]);
        
        for (int i = 1; i < n; ++i) {
            while (!Q.empty() && Q.back().second <= nums[i]) {
                Q.pop_back();
            }
            
            Q.push_back(make_pair(i, nums[i]));
            
            if (Q.front().first + k <= i) Q.pop_front();
            
            if (i >= k - 1) {
                ans.push_back(max(Q.front().second, Q.back().second));
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
