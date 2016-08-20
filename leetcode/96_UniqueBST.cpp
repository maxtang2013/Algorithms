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
    int numTrees(int n) {
        int i, j;
        vector<int> num(n+1, 0);
        if (n <= 1) return 1;
        
        num[0] = 1;
        num[1] = 1;
        for (i = 2; i <= n; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                num[i] += num[j] * num[i - j - 1];
            }
        }
        return num[n];
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
    
    for (int n = 0; n < 10; ++n)
    {
        printf("%d\n", sln.numTrees(n));
    }
}

int main()
{
    Test0();
    
    return 0;
}
