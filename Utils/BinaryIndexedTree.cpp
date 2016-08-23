
class BinaryIndexedTree {
public:
    BinaryIndexedTree(const vector<int>& nums) {
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
    
    int sumRange(int i, int j) {
        if (i == 0) return Query(j);
        
        return Query(j) - Query(i-1);
    }
    
private:
    
    int Query(int i) {
        int sum = 0;
        ++i;
        while (i > 0) {
            sum += mTreeSum[i];
            i -= i & (-i);
        }
        return sum;
    }

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