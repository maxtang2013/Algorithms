#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //
        // Say, we have two bits to represent the state of the accumulated bit in the resulting numbers.
        // To do that, we use two integers, 'a', and 'b'.
        // During the accumulating process, if we meet a bit '1' in the input, we transfer the state, represented by
        // (a, b),
        //       (0, 0) means this bit has been transfered for 3*n times,
        //       (0, 1) means this bit has been transfered for 3*n + 1 times.
        //       (1, 0) means this bit has been transfered for 3*n + 2 times.
        //
        //
        // ab      c        next_a   next_b
        // 00      1          0        1
        // 01      1          1        0
        // 10      1          0        0
        // 00      0          0        0
        // 01      0          0        1
        // 10      0          1        0
        
        int a = 0, b = 0;
        for (int c:nums)
        {
            int next_a = (~a&b&c) | (a&~b&~c);
            b = (~a&~b&c) | (~a&b&~c);
            
            a = next_a;
        }
        
        return b;
    }
};

static void Test0()
{
    Solution sln;
}

int main()
{
    Test0();
    
    return 0;
}
