#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        sort(candidates.begin(), candidates.end());
        
        combination(ans, comb, candidates, 0, target);
        return ans;
    }
    
private:
    void combination(vector<vector<int>> &ans, vector<int>&comb, vector<int> &candidates, int k, int target) {
        
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = k; i < candidates.size(); ++i) {
            if (i == 0 || candidates[i] != candidates[i-1]) {
                if (candidates[i] > target) break;
                
                comb.push_back(candidates[i]);
                combination(ans, comb, candidates, i, target - candidates[i]);
                comb.pop_back();
            }
        }
    }
};

void Test0()
{
    Solution sln;
    vector<int> candidates = {2, 3, 6, 7};
    
    vector<vector<int>> ans = sln.combinationSum(candidates, 7);
    for (int i = 0;i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Test0();
    
    return 0;
}
