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

class Solution {
public:
    // A O(n + 2log(n)) solution. Beautiful!
    int kthSmallest(vector<vector<int>> &m, int k)
    {
        priority_queue<Entry, vector<Entry>, Comparator> Q;
        int n = (int) m.size();
        int i = 0;
        
        for (i = 0; i < n; ++i) {
            Entry e = {0, i, m[0][i]};
            Q.push(e);
        }
        
        for (i = 0; i < k - 1; ++i)
        {
            Entry e = Q.top();
            int x = e.x, y = e.y;
            Q.pop();
            
            if (x == n - 1) continue;
            
            Entry e1 = {x + 1, y, m[x+1][y]};
            Q.push(e1);
        }
        
        Entry e = Q.top();
        return e.val;
    }
    
    /***
     * My solution, using two binary searches. O(log(X)*log(n)*n).
     *
     **/
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lower = matrix[0][0];
        int upper = matrix[n-1][n-1];
        
        while (upper > lower)
        {
            int mid = (lower + upper + 1) / 2;
            if (countRange(matrix, mid) >= k)
            {
                upper = mid - 1;
            }
            else
            {
                lower = mid;
            }
        }
        
        if (countRange(matrix, lower) < k)
            ++lower;
        
        return lower;
    }
    
private:
    int countRange(vector<vector<int> >&matrix, int upper)
    {
        int n = matrix.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i)
        {
            vector<int> &row = matrix[i];
            int start = -1, end = n - 1;
        
            while (start < end)
            {
                int mid = (start + end + 1) / 2;
                if (row[mid] <= upper)
                {
                    start = mid;
                }
                else
                {
                    end = mid - 1;
                }
            }
            
            ans += start + 1;
        }
        return ans;
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
    vector<vector<int>> matrix = {
        { 1,  5,  9},
        {10, 11, 13},
        {13, 15, 15}
    };
    Solution sln;
    printf("%d\n", sln.kthSmallest(matrix, 8));
}

void Test1()
{
    vector<vector<int>> matrix = {
        { 1, 2},
        { 3, 3}
    };
    Solution sln;
    printf("%d\n", sln.kthSmallest(matrix, 2));
}


int main()
{
    Test0();
    Test1();
    return 0;
}
