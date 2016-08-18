#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <stdlib.h>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        long long D = denominator;
        long long N = numerator;
        
        if (D < 0) {
            D = -D;
            N = -N;
        }
        
        int sign = 1;
        if (N < 0)
        {
            N = -N;
            sign = -1;
        }
        
        string fraction;
        map<int, int> visited;
        int k = 1;
        
        int decimal = (int)( N / D );
        N = N % D;
        
        while (N > 0)
        {
            if (visited[N])
            {
                int j = visited[N];
                // TODO:
                // 0.031324(124324)
                // 0.01(1)
                
                string s1 = fraction.substr(0, j-1);
                string s2 = fraction.substr(j-1);
                int i1 = s1.length() - 1, i2 = s2.length() - 1;
                while (i1 >= 0 && i2 >= 0 && s1[i1] == s2[i2])
                {
                    --i1; --i2;
                }
                
                s1 = s1.substr(0, i1 + 1); s2 = s2.substr(i2 + 1) + s2.substr(0, i2 + 1);
                
                fraction = s1 + "(" + s2 + ")";
                
                break;
            }
            
            visited[N] = k;
            int i = 0;
            while (N < D)
            {
                N *= 10;
                if (i++ > 0)
                {
                    fraction.append(1, '0');
                    ++k;
                }
            }
            
            int x = N / D;
            fraction.append(1, (char)(x + '0'));
            ++k;
            
            N = N % D;
        }
        string ans;
        char num[36];
        
        if (fraction.length() == 0)
        {
            if (sign == -1)
                sprintf(num, "-%d", decimal);
            else
                sprintf(num, "%d", decimal);
        }
        else
        {
        
        if (sign == -1)
            sprintf(num, "-%d.", decimal);
        else
            sprintf(num, "%d.", decimal);
        }
        ans = num + fraction;
        return ans;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.fractionToDecimal(1, 3) << endl;
}

void Test1()
{
    Solution sln;
    cout << sln.fractionToDecimal(2, 5) << endl;
}

void Test2()
{
    Solution sln;
    cout << sln.fractionToDecimal(26, 17) << endl;

}

void Test3()
{
    Solution sln;
    cout << sln.fractionToDecimal(26, 7) << endl;
}

void Test4()
{
    Solution sln;
    cout << sln.fractionToDecimal(-50, 8) << endl;
}

void Test5()
{
    Solution sln;
    cout << sln.fractionToDecimal(1, 214748364) << endl;
}

void Test6()
{
    Solution sln;
    cout << sln.fractionToDecimal(1, 6) << endl;
}

void Test7()
{
    Solution sln;
    cout << sln.fractionToDecimal(-1, -2147483648) << endl;
}

void Test8()
{
    Solution sln;
    cout << sln.fractionToDecimal(2147483647,
                                  37) << endl;
}

void Test9()
{
    Solution sln;
    cout << sln.fractionToDecimal(1,
                                  90) << endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    
    return 0;
}
