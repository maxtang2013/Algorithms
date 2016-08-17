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

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, n = (int)nums.size();
        int val;
        
        for (i = 0; i < n; ++i)
        {
            val = nums[i];
            while (val > 0 && val <= n && val != i + 1)
            {
                if (nums[val - 1] == val) break;
                
                // swap, and make 'val' in the right position.
                nums[i] = nums[val - 1];
                nums[val - 1] = val;
                val = nums[i];
            }
        }
        
        for (i = 0; i < n && nums[i] == i + 1; ++i);
        
        printVector(nums);
        
        return i + 1;
    }
    
private:
    void swap(vector<int>& nums, int i, int j)
    {
        int x = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
    }
};


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
//    vector<int> nums = {1,2,0};
//    printf("%d\n", sln.firstMissingPositive(nums));
//    
//    vector<int> nums1 = {3,4,-1,1};
//    printf("%d\n", sln.firstMissingPositive(nums1));
    
    vector<int> nums3 = {1,1};
    printf("%d\n", sln.firstMissingPositive(nums3));
    
    vector<int> nums2 = {-1,4,2,1,9,10};
    printf("%d\n", sln.firstMissingPositive(nums2));
}

int main()
{
    Test0();
    
    return 0;
}
