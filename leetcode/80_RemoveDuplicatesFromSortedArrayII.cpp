#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        int dupCnt = 0;
        int fillPos = -1;
        for (int i = 1; i < n; ++i) {
            if ( nums[i] == nums[i-1] ) {
                if (++dupCnt > 1) {
                    if (fillPos == -1) {
                        fillPos = i;
                    }
                    continue;
                }
            } else {
                dupCnt = 0;
            }
            
            if (fillPos > -1)
                nums[fillPos++] = nums[i];
        }
        
        if (fillPos == -1) fillPos = n;
        return fillPos;
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
    vector<int> nums = {1,1,1,2,2,3,3,3,3,4,4,4,4,4,4,};
    cout << sln.removeDuplicates(nums) << endl;
    printVector(nums);
}

int main()
{
    Test0();
    
    return 0;
}
