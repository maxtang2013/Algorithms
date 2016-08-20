#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

class Solution {
public:
    int maxProfitO_n(vector<int>& prices) {
        int n = (int)prices.size();
        vector<int> profit(n+1, 0);
        int i;
        
        if (n < 2) return 0;
        
        profit[0] = 0;
        profit[1] = 0;
        
        for (i = 2; i <= n; ++i)
        {
            profit[i] = profit[i-1];
            profit[i] = max(profit[i], prices[i - 1] - prices[0]);
            
            for (int j = 1; j < i - 1; ++j)
            {
                profit[i] = max(profit[i], profit[j - 1] + prices[i - 1] - prices[j]);
            }
        }
        
        return profit[n];
    }
    
    // O(n) solution
    int maxProfit(vector<int> &prices)
    {
        int n = (int)prices.size();
        if (n == 0) return 0;
        
        int bought[2] = {-prices[0], 0}, sold[2] = {0}, rest[2] = {0};
        int i;
        
        for (i = 1; i < n; ++i)
        {
            bought[1] = max(bought[0], rest[0] - prices[i]);
            sold[1] = bought[0] + prices[i];
            rest[1] = sold[0];
            
            sold[0] = sold[1];
            bought[0] = bought[1];
            rest[0] = rest[1];
        }
        
        
        return max(sold[1], rest[1]);
    }
    
};

void Test0()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 0, 2};
    printf("%d\n", sln.maxProfit(nums));
}


void Test1()
{
    Solution sln;
    vector<int> nums = {1, 2};
    printf("%d\n", sln.maxProfit(nums));
}

void Test2()
{
    Solution sln;
    vector<int> nums = {1};
    printf("%d\n", sln.maxProfit(nums));
}


int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
