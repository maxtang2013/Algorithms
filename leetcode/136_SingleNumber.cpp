#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0, i;
        for (i = 0; i < nums.size(); ++i)
        {
            n = n ^ nums[i];
        }
        return n;
    }
};



int main()
{
    Solution sln;
    return 0;
}
