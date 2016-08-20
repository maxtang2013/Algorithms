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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        mObstacleGrid = obstacleGrid;
        
        mNumPaths.resize(m);

        for (int i = 0; i < m; ++i)
        {
            mNumPaths[i].assign(n, 0);
        }
        if (obstacleGrid[0][0] == 0)
            mNumPaths[0][0] = 1;
        
        return paths(m-1, n-1);
    }
    
private:
    
    int C(int m, int n)
    {
        if (m - n < n)
        {
            n = m - n;
        }
        
        long long res = 1;
        for (int i = 0; i < n; ++i)
        {
            res = res * (m-i) / (i+1);
        }
        return (int)res;
    }
    
    int paths(int x, int y)
    {
        if (mNumPaths[x][y])
            return mNumPaths[x][y];
        
        if (mObstacleGrid[x][y] == 1) return 0;
        
        int cnt = 0;
        if (x > 0 && mObstacleGrid[x-1][y] == 0)
        {
            cnt += paths(x-1, y);
        }
        if (y > 0 && mObstacleGrid[x][y-1] == 0)
            cnt += paths(x, y-1);
        
        return mNumPaths[x][y] = cnt;
    }
    
    vector<vector<int>> mNumPaths;
    vector<vector<int>> mObstacleGrid;
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
    
    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    printf("%d\n", sln.uniquePathsWithObstacles(grid));
}

void Test1()
{
    Solution sln;
    
    vector<vector<int>> grid = {
        {1}
    };
    printf("%d\n", sln.uniquePathsWithObstacles(grid));
}


int main()
{
    Test0();
    
    return 0;
}
