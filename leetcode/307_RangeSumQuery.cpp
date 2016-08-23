#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class NumArray {
public:
    NumArray(const vector<int>& nums) {
        int p = 1;
        while (p < nums.size()) p *= 2;
        mOrigin = nums;
        mMaxVal = p + 1;
        mTreeSum.resize(p+1, 0);
        for (int i = 1; i <= nums.size(); ++i)
            Add(i-1, nums[i-1]);
    }
    
    void update(int i, int val) {
        Add(i, val - mOrigin[i]);
        mOrigin[i] = val;
    }
    
    int Query(int i) {
        int sum = 0;
        ++i;
        while (i > 0) {
            sum += mTreeSum[i];
            i -= i & (-i);
        }
        return sum;
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return Query(j);
        
        return Query(j) - Query(i-1);
    }
    
private:
    void Add(int i, int val) {
        ++i;
        while (i < mMaxVal) {
            mTreeSum[i] += val;
            i += i & (-i);
        }
    }
    
private:
    vector<int> mOrigin;
    vector<int> mTreeSum;
    int mMaxVal;

};

void Test0()
{
    vector<int> nums = {1, 3, 5};
    NumArray array(nums);
    
    printf("%d\n", array.sumRange(0, 2));
    array.update(1, 2);
    printf("%d\n", array.sumRange(0, 2));
}

void Test1()
{
    vector<int> nums = {7,2,7,2,0};
    NumArray arr(nums);
    arr.update(4,6); //{7,2,7,2,6}
    arr.update(0,2); //{2,2,7,2,6}
    arr.update(0,9); //{9,2,7,2,6}
    printf("%d\n",arr.sumRange(4,4)); // 6
    arr.update(3,8); //{9,2,7,8,6}
    printf("%d\n",arr.sumRange(0,4)); // 32
    arr.update(4,1); //{9,2,7,8,1}
    printf("%d\n", arr.sumRange(0,3)); // 26
    printf("%d\n", arr.sumRange(0,4)); // 27
    arr.update(0,4);
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
