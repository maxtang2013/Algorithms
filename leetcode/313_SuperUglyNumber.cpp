#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};


// priority_queue<Entry, vector<Entry>, Comparator> Q;


class Solution {
    struct Comparator {
        bool operator()(int e1, int e2)
        {
            return e1 > e2;
        }
    };
public:
    
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        int k = (int) primes.size();
        vector<int> ugly(n, 1);
        vector<int> index(k, 0);
        
        for (int i = 1; i < n; ++i)
        {
            int m = INT_MAX;
            for (int j = 0; j < k; ++j)
            {
                int next = primes[j] * ugly[index[j]];
                if (next == ugly[i-1])
                {
                    ++index[j];
                    next = primes[j] * ugly[index[j]];
                }
                
                m = min(m, next);
            }
            ugly[i] = m;
        }
        return ugly[n-1];
    }
    
    int nthSuperUglyNumber1(int n, vector<int>& primes) {
        long long prod;
        int k = (int) primes.size();
        priority_queue<int, vector<int>, Comparator> Q;
        Q.push(1);
        
        while (!Q.empty())
        {
            long long val = Q.top();
            
            do {
                int v1 = Q.top();
                if (v1 == val) Q.pop();
                else break;
            } while (!Q.empty());
            
            if (--n == 0)
            {
                return (int)val;
            }
            
            for (int i = 0; i < k; ++i)
            {
                prod = val * primes[i];
                if (prod <= INT_MAX)
                {
                    Q.push((int)prod);
                }
            }
        }
        return 0;
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
    vector<int> primes = {2, 7, 13, 19};
    printf("%d\n", sln.nthSuperUglyNumber(12, primes));
}

int main()
{
    Test0();
    
    return 0;
}
