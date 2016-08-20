#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        mRes.clear();
        mUsd.assign(10, 0);
        mComb.assign(k, 0);
        
        mK = k;
        comb(1, 1, n);
        return mRes;
    }
    
private:
    void comb(int s, int k, int n)
    {
        if (k == mK + 1)
        {
            if (n == 0)
            {
                mRes.push_back(mComb);
            }
            return;
        }
        
        int r = mK - k;
        if (r > 0 && ((1 + r) * r / 2 > n || (9 + 9 - r + 1) * r / 2 < n))
            return;
        
//        if (k < mK && (
//                          (mK - k) * (19 - mK + k) / 2 < n
//                       || (mK - k) * (1 + mK - k) / 2 > n
//                      )
//           )
//            return;
        
        for (int i = s; i < 10; ++i)
        {
            if (!mUsd[i])
            {
                mUsd[i] = 1;
                mComb[k-1] = i;
                comb(i + 1, k + 1, n - i);
                mUsd[i] = 0;
            }
        }
    }
    int mK;
    vector<int> mComb;
    vector<vector<int>> mRes;
    vector<int> mUsd;
};
void printBoard(const vector<vector<int>> &list)
{
    for (int i = 0; i < list.size(); ++i)
    {
        int n = list[i].size();
        for (int j = 0; j < n; ++j)
        {
            std::cout << list[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
}

void Test0()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(3, 7);
    printBoard(list);
}

void Test1()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(0, 7);
    printBoard(list);
}

void Test2()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(0, 0);
    printBoard(list);
}

void Test3()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(0, 1);
    printBoard(list);
}

void Test4()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(3, 15);
    printBoard(list);
}
void Test5()
{
    Solution sln;
    
    vector<vector<int>> list = sln.combinationSum3(6, 30);
    printBoard(list);
}

int main()
{
//    Test0();
//    Test1();
//    Test2();
//    Test3();
    Test4();
    Test5();
    
    return 0;
}
