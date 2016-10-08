#include <iostream>
#include <vector>
#include <bitset>
#include <queue>


//There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
//Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
//We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
//Find the last number that remains starting with a list of length n.
//
//Example:
//
//Input:
//n = 9,
//1 2 3 4 5 6 7 8 9
//2 4 6 8
//2 6
//6
//
//Output:
//6

using namespace std;
class Solution {

public:
    int lastRemaining(int n) {
        return lastRemaining(n, true) + 1;
    }
    
private:
    int lastRemaining(int n, bool fromLeft) {
        if (n == 1) return 0;
        
        // 0 1 2 3 4 5 6 7 8
        // 1 2 3 4 5 6 7 8 9
        //   2   4   6   8
        //   2       6
        //           6
        
        int last = lastRemaining(n/2, !fromLeft);
        if (!fromLeft && n%2==0) {
            last = last * 2;
        } else {
            last = last * 2 + 1;
        }
        return last;
    }
public:
    int Josephus(int n, int m) {
        int last = 0;
        
        // k, k+1, ..., i-1,    0,   1,     ...,  k-2
        // 0, 1,        i-1-k,  i-k, i-k+1, ...,  i-2,
        
        for (int i = 2; i <= n; ++i) {
            last = (last + m) % i;
        }
        
        return last + 1;
    }
};

void Test0()
{
    Solution sln;
    cout << sln.lastRemaining(9) << endl;
    cout << sln.Josephus(10, 2) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
