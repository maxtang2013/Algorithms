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

// DP
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        mNums.push_back(1);
        mNums.insert(mNums.end(), nums.begin(), nums.end());
        mNums.end();
        mNums.push_back(1);
        mN = mNums.size();
        
        mMaxVal.resize(mN);
        for (int i = 0; i < mN; ++i)
        {
            mMaxVal[i].assign(mN, -1);
        }
        
        return maxCoins(0, mN - 1);
    }
private:
    int maxCoins(int left, int right)
    {
        if (left + 1 == right) return 0;
        
        if (mMaxVal[left][right] > -1)
            return mMaxVal[left][right];
        
        int val = -1;
        for (int i = left+1; i < right; ++i)
        {
            val = max(val, mNums[left] * mNums[i] * mNums[right] + maxCoins(left, i) + maxCoins(i, right));
        }
        return mMaxVal[left][right] = val;
    }
    
private:
    vector<int> mNums;
    int mN;
    vector<vector<int>> mMaxVal;
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
    vector<int> nums = {3,1,5,8};
    printf("%d\n", sln.maxCoins(nums));
}

int main()
{
    Test0();
    
    return 0;
}
