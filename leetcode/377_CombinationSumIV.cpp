#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    int combinationSum4_1(vector<int>& nums, int target) {
        int *dp = new int[target + 1];
        int res = 0;
        int n = nums.size();
        int i, j;
        
        memset (dp, 0, (target + 1) * sizeof(int));
        
        dp[0] = 1;
        for (i = 0; i < target; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                int x = i + nums[j];
                if (x <= target)
                {
                    dp[x] += dp[i];
                }
            }
        }
        
        res = dp[target];
        delete[] dp;
        
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        mNumArr = nums;
        mNum = nums.size();
        
        return getComb(target);
    }
    
    int getComb(int target)
    {
        if (target == 0)
        {
            return 1;
        }
        
        if (mComb.count(target) > 0)
        {
            return mComb[target];
        }
        
        int cnt = 0;
        for (int i = 0; i < mNum; ++i)
        {
            if (target >= mNumArr[i])
            {
                cnt += getComb(target - mNumArr[i]);
            }
        }
        mComb[target] = cnt;
        return cnt;
    }
private:
    vector<int> mNumArr;
    int mNum;
    map<int, int> mComb;
};

void Test0()
{
    Solution sln;
    vector<int> nums = {1, 2, 3};
    printf("%d\n", sln.combinationSum4(nums, 4));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {11111111, 22222222, 33333333};
    printf("%d\n", sln.combinationSum4(nums, 44444444));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
