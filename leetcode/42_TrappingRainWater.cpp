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
};

void Test0()
{
    Solution sln;
    vector<int> ht = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", sln.trap(ht));
}

int main()
{
    Test0();
    
    return 0;
}
