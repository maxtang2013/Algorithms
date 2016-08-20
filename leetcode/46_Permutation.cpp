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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        mNums = nums;
        mRow.assign(n, 0);
        mAns.clear();
        mUsd.assign(n, 0);
        
        perm(n, 0);
        
        return mAns;
    }
    
private:
    
    void perm(int n, int k)
    {
        if (k == n)
        {
            mAns.push_back(mRow);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!mUsd[i])
            {
                mUsd[i] = 1;
                mRow[k] = mNums[i];
                perm(n, k + 1);
                mUsd[i] = 0;
            }
        }
    }
    
    vector<int> mRow;
    vector<int> mUsd;
    vector<int> mNums;
    vector<vector<int>> mAns;
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
}

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
    
    vector<int> nums = {1, 4, 5};
    vector<vector<int>> ans = sln.permute(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Test0();
    
    return 0;
}
