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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isPalindrome(int x) {
        
        while (x >= 0) {
            if (x >= 0 && x < 10) return true;
            
            long long p = 10;
            int prevp = 1;
            long long lastDigit = x % 10;
            if (lastDigit == 0) return false;
            
            x -= lastDigit;
            while (p <= x) {
                lastDigit *= 10;
                prevp = (int)p;
                p *= 10;
            }
            
            // The variable 'lastDigit' can be greater then INT_MAX here.
            if (lastDigit > x) return false;
            
            if (x - lastDigit >= prevp) return false;
            
            x -= lastDigit;
            
            // Dealing with leading zeros.
            while (x % 10 == 0 && prevp >= 100 && x < prevp) {
                prevp /= 100;
                x /= 10;
            }
            
            if (x > 0 && prevp > x) return false;
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
//    printf("%d\n", sln.isPalindrome(1100011));
//    printf("%d\n", sln.isPalindrome(11030011));
//    printf("%d\n", sln.isPalindrome(110303011));
//    printf("%d\n", sln.isPalindrome(INT_MAX));
    printf("%d\n", sln.isPalindrome(1410110141));
}

int main()
{
    Test0();
    
    return 0;
}
