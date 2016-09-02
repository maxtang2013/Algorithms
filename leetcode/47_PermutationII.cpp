#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm;
        
        mVisited.resize(nums.size(), false);
        mAns.clear();
        perm.resize(nums.size());
        
        generatePerm(nums, 0, perm);
        
        return mAns;
    }
private:
    void generatePerm(const vector<int>& nums, int k, vector<int>& perm) {
        int n = (int) nums.size();
        if (k == n) {
            mAns.push_back(perm);
            return;
        }
        unordered_map<int, bool> visitedHere;
        
        for (int i = 0; i < n; ++i) {
            if (!mVisited[i] && !visitedHere.count(nums[i])) {
                visitedHere[nums[i]] = 1;
                mVisited[i] = 1;
                perm[k] = nums[i];
                generatePerm(nums, k+1, perm);
                mVisited[i] = 0;
            }
        }
    }
    
    vector<vector<int>> mAns;
    vector<int> mVisited;
};


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
    vector<int> nums = {1, 2, 1, 3};
    printBoard(sln.permuteUnique(nums));
}

int main()
{
    Test0();
    
    return 0;
}
