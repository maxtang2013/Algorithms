#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int myAtoi(string str) {
            int i, sign = 1;
            long long ans = 0;
            int len = (int) str.length();
            
            i = 0;
            while (i < len && isspace(str[i])) ++i;
            
            if (i < len && str[i] == '+') ++i;
            else if (i < len && str[i] == '-') { sign = -1; ++i; };
            
            while (i < len && str[i] >= '0' && str[i] <= '9')
            {
                ans = ans * 10 + str[i] - '0';
                
                if (ans >= INT_MAX && sign == 1)
                {
                    ans = INT_MAX;
                    break;
                }
                if (ans > INT_MAX + (long long)1 && sign == -1)
                {
                    ans = INT_MIN;
                    break;
                }
                ++i;
            }
            
            if (sign == -1 && ans > INT_MIN)
                ans *= -1;
            
            return (int)ans;
        }
};



int main()
{
    Solution sln;
    printf("%d\n", sln.myAtoi("good"));
    
    printf("%d\n", sln.myAtoi("3124"));
    printf("%d\n", sln.myAtoi("112445567889999787766"));
    printf("%d\n", sln.myAtoi("-1334421111111111111"));
    return 0;
}
