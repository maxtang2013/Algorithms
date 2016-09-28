#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;
//Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n]
//inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
//
//Example 1:
//nums = [1, 3], n = 6
//Return 1.
//
//Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
//Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
//Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
//So we only need 1 patch.
class Solution {
public:
    //
    // If we can construct all numbers in range [1 .. m] by using a[0:i-1], then with another number x, NOT larger than (m + 1),
    // we will be able to construct all numbers not larger than x + m. If, however, we are given that the next number is larger than
    // m + 1, we must add another number to construct m+1, as we are already able to construct every number in [1 .. m],
    // we take a GREEDY approach, we add m+1 to the array.
    //
    // So our strategy is simple, every time we take the next number from the given array, we check if
    // maxNumber : the maximum number we can construct so far.
    //
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long maxNumber = 0;
        int i = 0;
        
        sort (nums.begin(), nums.end());
        while (maxNumber < n) {
            if (i < nums.size() && nums[i] <= maxNumber + 1) {
                maxNumber += nums[i++];
            } else {
                maxNumber += maxNumber + 1;
                ++ans;
            }
        }
        return ans;
    }
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = (int)list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}
void Test0()
{
    Solution sln;
    vector<int> nums = {1, 5, 10};
    cout << sln.minPatches(nums, 20) << endl;
}
void Test1() {
    vector<int> nums = {1,2,31,33};
    
    Solution sln;
    cout << sln.minPatches(nums, 2147483647) << endl;
}

void Test2() {
    vector<int> nums = {1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94};
    
    Solution sln;
    cout << sln.minPatches(nums, 20) << endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
