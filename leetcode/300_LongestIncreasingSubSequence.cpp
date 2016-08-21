#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> smallestTailForSequenceOfLength(n, 0);
        int longestLength = 0;
        
        for (int x : nums) {
            int i = 0, j = longestLength;
            
            while (i < j) {
                int mid = (i + j) / 2;
                
                if (smallestTailForSequenceOfLength[mid] < x)
                    i = mid + 1;
                else
                    j = mid;
            }
            smallestTailForSequenceOfLength[i] = x;
            longestLength = max(longestLength, i+1);
        }
        return longestLength;
    }
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

void Test0()
{
    Solution sln;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("%d\n", sln.lengthOfLIS(nums));
}

int main()
{
    Test0();
    
    return 0;
}
