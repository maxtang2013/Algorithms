#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
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
    //    for (i = 0; i < 32; ++i)
    //    {
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //        mask = mask << 1;
    //    }
    
    return n & (-n);
}

void printBits(int n)
{
    for (int i = 31; i >= 0; --i)
    {
        if (n & (1<<i)) std::cout << "1";
        else std::cout << "0";
    }
    std::cout << "\n";
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


int main()
{
    Solution sln;
    return 0;
}
