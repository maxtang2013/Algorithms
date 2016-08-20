#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        mN = n;
        mStr.assign(2*n, ' ');
        mAns.clear();
        
        generate(n, n);
        return mAns;
    }
    
private:
    void generate(int n1, int n2)
    {
        if (n1 == 0 && n2 == 0)
        {
            mAns.push_back(mStr);
            return;
        }
        if (n1 > n2)
            return;
        
        int k = mN * 2 - (n1 + n2);
        if (n1 > 0)
        {
            mStr[k] = '(';
            generate(n1 - 1, n2);
        }
        
        if (n2 > n1 && n1 >= 0)
        {
            mStr[k] = ')';
            generate(n1, n2 - 1);
        }
    }
    
    vector<string> mAns;
    string mStr;
    int mN;
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << "\n";
        else std::cout << "\n";
    }
}


void Test0()
{
    Solution sln;
    for (int i = 0; i < 4; ++i)
    {
    vector<string> ans = sln.generateParenthesis(i);
    printVector(ans);
        printf("\n");
    }
}

int main()
{
    Test0();
    
    return 0;
}
