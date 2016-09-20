#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAllDuplicates(vector<int>& nums) {
        vector<int> ans;
        nums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == i) continue;
            int j = i;
            while (nums[j] != j) {
                int t = nums[j];
                if (nums[t] == t) {
                    ans.push_back(t);
                    break;
                }
                
                int tmp = nums[t];
                nums[t] = t;
                nums[j] = tmp;
            }
        }
        return ans;
    }
};

void printVector(const vector<int> ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<int> nums = {1,3,2};
    printVector(sln.findAllDuplicates(nums));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1,3,1,2,4,5,2,1,1};
    printVector(sln.findAllDuplicates(nums));
}

int main()
{
    Test0();
    Test1();
    return 0;
}