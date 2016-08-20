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
    
    bool searchMatrix_nlogm(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<int> &row = matrix[i];
            if (binary_search(row.begin(), row.end(), target))
                return true;
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        int row = 0, col = m - 1;
        
        //   -----------*   Say, (row, col) is the top right corner, and target is larger than the value at that position,
        //   ************   then, the first row can be ignored.
        //   ************
        //   ************
        //   ************
        
        //   ------------   Similarly, if we have moved to (row, col)  and target is smaller than the value at that
        //   ***********|   position, then the col'th column can be ignored.
        //   **********||
        //   **********||
        //   **********||
        
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            
            
            if (matrix[row][col] > target) {
                // target won't be in the lower part of the column, move left
                --col;
            } else {
                ++row;
            }
        }
        return false;
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

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
    vector<vector<int>> m = {{-5}};
    printf("%d\n", sln.searchMatrix(m, -2));
}

int main()
{
    Test0();
    
    return 0;
}
