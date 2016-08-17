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
    int countNumbersWithUniqueDigits(int n) {
        int arr[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        int cnt = 9;
        int i, j, k = 9;
        
        // prevent crash.
        if (n > 10) n = 10;
        
        for (i = 1; i < 11; ++i)
        {
            arr[i] = 9;
            k = 9;
            for (j = 1; j < i; ++j)
            {
                arr[i] *= k;
                --k;
            }
        }
        
        int ans = 0;
        for (i = 0; i <= n; ++i)
        {
            ans += arr[i];
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
    Solution sln;
    for (int i = 0; i < 11; ++i)
    {
        printf("%d\n", sln.countNumbersWithUniqueDigits(i));
    }
}

int main()
{
    Test0();
        return 0;
}
