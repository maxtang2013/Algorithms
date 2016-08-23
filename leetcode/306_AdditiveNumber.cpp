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
    bool isAdditiveNumber(string num) {
        int len = (int) num.length();
        int i, j;
    
        for (i = len-1; i > 1; --i) {
            
            if (i < len-1 && num[i] == '0') continue;
            string n2 = num.substr(i);
            
            for (j = i-1; j > 0; --j) {
                
                if (j<i-1 && num[j] == '0') continue;
                
                if (i - j > len - i) break;
                if (i - j == len -i && num.substr(j, i - j) > n2) break;
                
                
                if (checkValid(num, j, i, len))
                    return true;
            }
        }
        return false;
    }
    
private:
    bool checkValid(const string& num, int j, int i, int e)
    {
        if (j == 0) return true;
        vector<char> n0;
        int borrow = 0;
        for (int k = 0; k < e - i; ++k) {
            int x;
            int idx1 = e - 1 - k;
            int idx2 = i - 1 - k;
            int idx3 = j - 1 - k;
            if (idx2 >= j)
                x = num[idx1] - num[idx2] - borrow;
            else
                x = num[idx1] - '0' - borrow;
            
            if (x < 0) { x+=10; borrow = 1;}
            else borrow = 0;
            
            n0.push_back(x+'0');
        }
        
        while (n0.back() == '0') n0.pop_back();
        if (n0.empty()) n0.push_back('0');
        
        int l = (int) n0.size();
        if (j < l) return false;
        
        for (int k = j-l; k<j; ++k) {
            if (num[k] != n0.back()) return false;
            n0.pop_back();
        }
        
        return checkValid(num, j-l, j, i);
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
    
//    printf("expecting 1:%d\n", sln.isAdditiveNumber("123"));
//    printf("expecting 1:%d\n", sln.isAdditiveNumber("199100199"));
//    printf("expecting 1:%d\n", sln.isAdditiveNumber("12358132134"));
//    printf("expecting 0:%d\n", sln.isAdditiveNumber("1023"));
    printf("expecting 1:%d\n", sln.isAdditiveNumber("101"));
    printf("expecting 1:%d\n", sln.isAdditiveNumber("000"));
}

int main()
{
    Test0();
    
    return 0;
}
