#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


// Solution1, 29ms
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        mBest = INT_MIN;
        mArraySize = nums.size();
        dfs(nums, 0, 3, target, 0);
        return mBest;
    }
    
private:
    void dfs(const vector<int>& nums, int i, int k, int target, int curr) {
        if (k == 0) {
            if (mBest == INT_MIN || abs(target - curr) < mGap) {
                mBest = curr;
                mGap = abs(target - curr);
            }
            return;
        }
        
        int start = i, end = mArraySize;
        if (mBest != INT_MIN) {
            
            // Pruning 1, from 249ms to 162ms
            if (k * nums[mArraySize-1] + curr <= target - mGap) return;
            if (k * nums[i] + curr >= target + mGap) return;
            
            int lo = i, hi = mArraySize;
            
            // Pruning 2 Binary search for possible range, from 162ms to 42ms
            
            // Optimaze 4: avoid recalculate smallest in loop, from 29ms to 26ms.
            int smallest = target - mGap - curr - (k-1) * nums[mArraySize - 1];
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] <= smallest) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            start = lo;
            if (start >= mArraySize) return;
            
            int largest = target + mGap - curr - (k-1) * nums[start];
            lo = i, hi = mArraySize;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] >= largest) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            end = hi;
        }
        
        for (int j = start; j < end; ++j) {
            dfs(nums, j+1, k-1, target, curr+nums[j]);
            
            // Pruning 3. From 42ms to 29ms.
            // skip same element.
            while (j < mArraySize - 1 && nums[j+1] == nums[j]) ++j;
        }
    }
    
private:
    int mArraySize;
    int mBest;
    int mGap;
};

void Test0()
{
    Solution1 sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
