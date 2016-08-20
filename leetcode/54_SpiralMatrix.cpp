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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        ans.reserve(matrix.size() * matrix.size());
        fill(matrix, matrix[0].size() - 1, matrix.size() - 1, 0, 0, ans);
        return ans;
    }
    
    void fill(const vector<vector<int>> &m, int width, int height, int left, int top, vector<int>& output)
    {
        int right = left + width;
        int bottom = top + height;
        int i;
        
//        if (width == 0 && height == 0)
//        {
//            output.push_back(m[top][left]);
//            return;
//        }
        if (width == 0)
        {
            for (i = top; i <= bottom; ++i)
                output.push_back(m[i][left]);
            return;
        }
        if (height == 0)
        {
            for (i = left; i <= right; ++i)
                output.push_back(m[top][i]);
            return;
        }
        
        for (i = left; i < right; ++i)
        {
            output.push_back(m[top][i]);
        }
        for (i = top; i < bottom; ++i)
            output.push_back(m[i][right]);
        for (i = right; i > left; --i)
            output.push_back(m[bottom][i]);
        for (i = bottom; i > top; --i)
            output.push_back(m[i][left]);
        
        if (width >=2 && height >= 2)
            fill(m, width-2, height-2, left + 1, top + 1, output);
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
}

void Test0()
{
    Solution sln;
    vector<vector<int>> m = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    printVector(sln.spiralOrder(m));
}

void Test1()
{
    Solution sln;
    vector<vector<int>> m = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12},
        { 13,14, 15, 16}
    };
    printVector(sln.spiralOrder(m));
}
void Test2()
{
    Solution sln;
    vector<vector<int>> m = {{6,9,7}};
    printVector(sln.spiralOrder(m));
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
