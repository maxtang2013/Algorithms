#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<int>> ans;
        sort (nums.begin(), nums.end());
        for (int mask = 0; mask < (1<<n); ++mask) {
            vector<int> s;
            bool valid = true;
            for (int i=1; i<n; ++i) {
                if (nums[i] == nums[i-1] && (mask & (1<<i)) == 0 && ((mask & (1<<(i-1))) > 0)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            for (int i = 0; i < n; ++i) {
                if (mask & (1<<i)) {
                    s.push_back(nums[i]);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
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
    vector<int> nums = {1, 1, 2, 3, 5, 5, 4};
    printBoard(sln.subsetsWithDup(nums));
}

int main()
{
    Test0();
    
    return 0;
}
