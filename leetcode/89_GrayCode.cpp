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
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n == 0)
        {
            ans.push_back(0);
            return ans;
        }
        
        ans = grayCode(n - 1);
        int cnt = 1<<(n-1);
        for (int i = 0; i < cnt; ++i)
        {
            ans.push_back(ans[cnt - 1 - i] + cnt);
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

void Test0()
{
    Solution sln;
    for (int n = 0; n < 6; ++n)
        printVector(sln.grayCode(n));
}

int main()
{
    Test0();
    
    return 0;
}
