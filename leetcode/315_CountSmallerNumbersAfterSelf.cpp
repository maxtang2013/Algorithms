#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;


// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
// Given nums = [5, 2, 6, 1]
//
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//Return the array [2, 1, 1, 0].
//
//
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return nums;
        
        unordered_map<int, int> count;
        int n = (int) nums.size();
        vector<int> ans(n, 0);
        int mi = INT_MAX;
        for (int i = 0; i < n; ++i) {
            mi = min(mi, nums[i]);
        }
        --mi;
        
        for (int i = 0; i < n; ++i) {
            nums[i] -= mi;
        }
        
        for (int i = n-1; i >= 0; --i) {
            int k = nums[i] - 1;
            int cnt = 0;
            while (k > 0) {
                cnt += count[k];
                k = k & (k - 1);
            }
            ans[i] = cnt;
            
            k = nums[i];
            int mask = 0;
            do {
                count[k]++;
                mask = k & (-k);
                k += mask;
            } while (mask < (1<<30));
        }
        return ans;
    }
};
template<typename T>
void printVector(const vector<T>& list)
{
    int len = (int) list.size();
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
    vector<int> nums = {5, 2, 6, 1};
    printVector(sln.countSmaller(nums));
}

int main()
{
    Test0();
    
    return 0;
}
