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

int sTarget = 0;

int guess(int num) {
    if (sTarget < num) return -1;
    if (sTarget == num) return 0;
    return 1;
};

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        
        while (low < high) {
            int mid = (low + (long long)high) / 2;
            int res = guess(mid);
            
            if (res == 0) return mid;
            
            if (res < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return guess(low) == 0 ? low : low - 1;
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
    
    sTarget = 8;
    printf("%d\n", sln.guessNumber(20));
}

void Test1()
{
    
    Solution sln;
    
    sTarget = 1702766719;
    printf("%d\n", sln.guessNumber(2126753390));
}

int main()
{
    // Test0();
    Test1();
    
    return 0;
}
