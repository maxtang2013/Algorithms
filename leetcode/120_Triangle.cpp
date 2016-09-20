#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> minSum[2] = {vector<int>(n), vector<int>(n)};
        
        minSum[0][0] = triangle[0][0];
        
        int curr = 0, next = 1;
        for (int i = 0; i < n-1; ++i) {
            
            minSum[next][0] = minSum[curr][0] + triangle[i+1][0];
            for (int j = 1; j <= i; ++j) {
                minSum[next][j] = min(minSum[curr][j], minSum[curr][j-1]) + triangle[i+1][j];
            }
            minSum[next][i+1] = minSum[curr][i] + triangle[i+1][i+1];
            
            swap(curr, next);
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) ans = min(ans, minSum[curr][i]);
        return ans;
    }
};

void Test0()
{
    Solution sln;
    vector<vector<int>> tri = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << sln.minimumTotal(tri) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
