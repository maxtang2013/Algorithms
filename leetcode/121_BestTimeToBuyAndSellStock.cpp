#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        vector<int> S;
        S.reserve(n);
        int profit = 0;
        
        for (int i = 0; i < n; ++i) {
            while (!S.empty() && S.back() >= prices[i]) {
                profit = max(profit, S.back() - S.front());
                S.pop_back();
            }
            S.push_back(prices[i]);
        }
        
        if (!S.empty())
            profit = max(profit, S.back() - S.front());
        
        return profit;
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
    vector<int> p = {7, 1, 5, 3, 6, 4};
    cout << sln.maxProfit(p) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
