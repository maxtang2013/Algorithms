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
    int superPow(int a, vector<int>& b) {
        const int mod = 1337;
        int r[mod] = {0};
        bool vst[mod] = {0};
        int loopLen = 0;
        a = a % mod;
        int p = a;
        
        if (a == 0) return 0;
        
        for (int i = 0; i < mod; ++i)
        {
            if (vst[p]) {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (r[j] == p)
                    {
                        loopLen = i - j;
                        break;
                    }
                }
                
                break;
            }
            vst[p] = 1;
            r[i] = p;
            p = p * a % mod;
        }
        
        int t = 0;
        for (int i = 0; i < b.size(); ++i) {
            t = (t * 10 + b[i]) % loopLen;
        }
        
        if (t == 0) t = loopLen;
        
        
        
        return r[t-1];
    }
    
    int getSum(int a, int b) {
        int mask = 1;
        int carry = 0;
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            int a1 = a&mask, b1 = b&mask;
            
            ans |= a1 ^ b1 ^ carry;
            
            carry = ((a1 & b1) || (a1 & carry) || (b1 & carry)) ? mask << 1 : 0;
            
            mask = mask << 1;
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
    vector<int> b = {1,0};
    for (int  k = 2; k < 1337; ++k)
    printf("%d\n", sln.superPow(k, b));
}

int pow(int a, int b, int mod)
{
    int mask = 1;
    int p = a;
    int ans = 1;
    
    for (int i = 0; i < 11; ++i)
    {
        if (b & mask) ans = (ans * p) % mod;
        p = p*p % mod;
        mask = mask << 1;
    }
    return ans;
}

void Check()
{
    int cnt = 0;
    
    for (int i = 2; i < 1337; ++i)
    {
        bool visited[1337] = {0};
        int r = i;
        for (int j = 0; j < 1337; ++j)
        {
            r = r * i % 1337;
        }
    }
    
    
    for (int i = 2; i < 191; ++i)
    {
        int ans = pow(i, 190, 191);
        printf("%d ", ans);
    }

}

void Test2() {
    Solution sln;
    printf("%d\n", sln.getSum(3, -2));
    printf("%d\n", sln.getSum(3, -2));
    printf("%d\n", sln.getSum(-147, 1));
}

int main()
{
    //Check();
    
    Test2();
    
    
    //printf("%d\n", cnt);
    
    return 0;
}
