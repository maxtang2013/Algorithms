#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

class Solution {
public:
    Solution(vector<int> nums)
    :mNums(nums)
    {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return mNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        mShuffled.resize(mNums.size());
        int i = 0;
        
        vector<int> remain(mNums);
        while (remain.size() > 0)
        {
            int n = remain.size();
            int r = rand() % n;
            
            mShuffled[i] = remain[r];
            remain[r] = remain[n-1];
            remain.pop_back();
            ++i;
        }
        return mShuffled;
    }
private:
    vector<int> mShuffled;
    vector<int> mNums;
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


int main()
{
    Solution sln;
    return 0;
}
