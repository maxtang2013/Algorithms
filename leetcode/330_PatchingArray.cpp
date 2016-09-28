#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        
        sort (nums.begin(), nums.end());
        
        long long maxNumber = 0;
        int i = 0;
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
