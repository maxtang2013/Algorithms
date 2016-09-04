#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1;
        int water = 0;
        while ( i + 1 < j ) {
            if (height[i] > height[j]) {
                int k = j - 1;
                while (k > i && height[k] < height[j]) {
                    water += height[j] - height[k];
                    --k;
                }
                
                j = k;
            } else {
                int k = i + 1;
                while (k < j && height[k] < height[i]) {
                    water += height[i] - height[k];
                    ++k;
                }
                i = k;
            }
        }
        return water;
    }
    
    int romanToInt(string s) {
        int n = (int)s.length();
        int i = 0;
        int ans = 0;
        while (i < n) {
            switch (s[i]) {
                case 'I':
                    ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    if (i > 0 && s[i-1] == 'I')
                        ans -= 2;
                    break;
                    
                case 'X':
                    ans += 10;
                    if (i > 0 && s[i-1] == 'I') ans -= 2;
                    break;
                case 'L':
                    ans += 50;
                    if (i > 0 && s[i-1] == 'X') ans -= 20;
                    break;
                
                case 'C':
                    ans += 100;
                    if (i > 0 && s[i-1] == 'X') ans -= 20;
                    break;
                case 'D':
                    ans += 500;
                    if (i > 0 && s[i-1] == 'C') ans -= 200;
                    break;
                case 'M':
                    ans += 100;
                    if (i > 0 && s[i-1] == 'C') ans -= 200;
                    
                default:
                    break;
            }
            ++i;
        }
        return ans;
    }
};

void Test0()
{
    Solution sln;
    vector<int> ht = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", sln.trap(ht));
    
    printf("%d\n", sln.romanToInt("XXXIV"));
}

int main()
{
    Test0();
    
    return 0;
}
