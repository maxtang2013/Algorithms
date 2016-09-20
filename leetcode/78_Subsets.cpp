#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        int maxN = (1<<n);
        vector<vector<int>> ans;
        for (int i = 0; i < maxN; ++i) {
            vector<int> s;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) s.push_back(nums[j]);
            }
            ans.push_back(s);
        }
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
