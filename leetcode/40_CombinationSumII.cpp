#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        sort(candidates.begin(), candidates.end());
        traverse(candidates, target, 0, ans);
        
        return ans;
    }
private:
    void traverse(const vector<int>& candidates, int target, int k, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(mComb);
            return;
        }
        int n = (int) candidates.size();
        for (int i = k; i < n; ++i) {
            if (candidates[i] > target) break;
            
            
            
            mComb.push_back(candidates[i]);
            traverse(candidates, target-candidates[i], i+1, ans);
            mComb.pop_back();
            
            while (candidates[i+1] == candidates[i]) ++i;
        }
    }
    
    vector<int> mComb;
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
    cout << endl;
}
template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    printBoard(sln.combinationSum2(nums, 8));
}

int main()
{
    Test0();
    
    return 0;
}
