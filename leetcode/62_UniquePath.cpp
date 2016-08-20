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
    int uniquePaths(int m, int n) {
        
//        mNumPaths.resize(m);
//        
//        for (int i = 0; i < m; ++i)
//        {
//            mNumPaths[i].assign(n, 0);
//        }
//        mNumPaths[0][0] = 1;
//        
//        return paths(m-1, n-1);
        return C(m + n - 2, m - 1);
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
        
        int cnt = 0;
        if (x > 0)
        {
            cnt += paths(x-1, y);
        }
        if (y > 0)
            cnt += paths(x, y-1);
        
        return mNumPaths[x][y] = cnt;
    }
    
    vector<vector<int>> mNumPaths;
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
    printf("%d\n", sln.uniquePaths(3, 7));
    
}

int main()
{
    Test0();
    
    return 0;
}
