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

struct Item {
    int rate;
    int index;
};

struct Comp {
    bool operator()(const Item &a, const Item &b)
    {
        return a.rate < b.rate;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 0);
        
        candies[0] = 1;
        int sum = 0;
        
        int height = 1;
        
        candies[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                ++height;
            } else {
                height = 1;
            }
            candies[i] = height;
        }
        
        height = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                ++height;
            } else {
                height = 1;
            }
            candies[i] = max(candies[i], height);
        }
        
        for (int c:candies) {
            sum += c;
        }
        
        return sum;
    }
    
    
//private:
//    int C (int left, int right, int low)
//    {
//        if (left + 1 == right)
//            return 0;
//        
//        if (mMinCandies[left][right][low] > INT_MIN)
//            return mMinCandies[left][right][low];
//        
//        int min = INT_MAX, j;
//        for (int i = left + 1; i < right; ++i)
//        {
//            if (mRating[i] > min)
//            {
//                j = i;
//                mRating = min;
//            }
//        }
//        int cnt = 0;
//        if (mRating[j]
//    }
//private:
//    int mN;
//    vector<int> mRating;
//    vector<vector<vector<int>>> mMinCandies;
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
    vector<int> nums = {1};
    printf("%d\n", sln.candy(nums));
    
    
}
            
void Test1()
{
    Solution sln;
    vector<int> nums = {1, 2};
    printf("%d\n", sln.candy(nums));
}

void Test2()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 1, 3, 5, 7, 6, 2, 1};
    printf("%d\n", sln.candy(nums));
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
