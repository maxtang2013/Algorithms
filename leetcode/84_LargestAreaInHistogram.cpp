#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        if (heights.empty()) return 0;
        
        int n = heights.size();
        int area = 0;
        vector<pair<int, int>> Stack;
        Stack.reserve(n+1);
        
        Stack.push_back(make_pair(0, heights[0]));
        
        int i = 1;
        while (i < n) {
            int j = i;
            while (!Stack.empty()) {
                pair<int, int> p = Stack.back();
                
                if (p.second <= heights[i]) break;
                    
                area = max(area, (i-p.first) * p.second);
                
                j = p.first;
                
                Stack.pop_back();
            }
            Stack.push_back(make_pair(j, heights[i]));
            ++i;
        }
        
        while (!Stack.empty()) {
            pair<int, int> p = Stack.back();
            area = max(area, (n-p.first) * p.second);
            Stack.pop_back();
        }
        return area;
    }
};

void Test0()
{
    Solution sln;
    
    vector<int> hts = {2, 1, 5, 6, 2, 3};
    
    
    cout << sln.largestRectangleArea(hts) << endl;
}

void Test1()
{
    Solution sln;
    
    vector<int> hts = {};
    
    
    cout << sln.largestRectangleArea(hts) << endl;
}


void Test2()
{
    Solution sln;
    
    vector<int> hts = {2, 1, 2};
    
    cout << sln.largestRectangleArea(hts) << endl;
}


int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
