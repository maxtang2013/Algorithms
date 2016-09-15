#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n/2) k = n / 2;
        
        if (k == 0) return 0;
        
        vector<int> bought(k, INT_MIN), sold(k, INT_MIN);
        
        for (int i = 0; i < n; ++i) {
            
            for (int j = k - 1; j > 0; --j) {
                if (i > j * 2)
                    sold[j] = max(bought[j] + prices[i], sold[j]);
                if (i > j * 2 - 1)
                    bought[j] = max(sold[j-1] - prices[i], bought[j]);
            }
            
            if (i > 0)
                sold[0] = max(sold[0], bought[0] + prices[i]);
            
            bought[0] = max(bought[0], -prices[i]);
        }
        
        int ans = 0;
        for (int j = 0; j < k; ++j) ans = max(ans, sold[j]);
        return ans;
    }
};

void Test0()
{
    Solution sln;
    
    vector<int> prices = {
        3, 1,2, 4, 1,2 ,4, 6
    };
    cout << sln.maxProfit(3, prices) << endl;
}

void Test1()
{
    Solution sln;
    vector<int> prices = {
        2,1,2,0,1
    };
    cout << sln.maxProfit(2, prices) << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
