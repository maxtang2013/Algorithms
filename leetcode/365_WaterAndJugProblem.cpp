#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

//You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
//If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
//Operations allowed:
//
//Fill any of the jugs completely with water.
//Empty any of the jugs.
//Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//
class Solution {
    int gcd(int m, int n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m%n);
    }
public:
    
    //Even with the Bézout's identity, I think it's necessary to prove that every z = ax - by in range [0, x+y] can be measured.
    //
    //Proof by INDUCTION.
    //If we can measure all z' = a'x - b'y with (a' + b') < (a+b), then we must also be able to measure z = ax - by, if 0 <= ax - by <= x+y.
    //
    //Notice that either (a-1) * x - by, or ax - (b-1)y must also be in the range [0, x+y].
    //If not, we must have (a-1) * x - by < 0, and ax - (b-1) * y > x + y, witch lead to ax - by < x and, ax - by > x. Conflicting!
    //
    //By assumption, both (a-1) * x - by* and ax - (b-1)y are measurable, if they are in range[0, x+y]
    //If 0 <= (a-1) * x - by <= x + y, with 0 <= ax - by <= x+y, we have 0 <= (a-1) * x - by <= y,
    //so we must be able to dump all (a-1)x-by litres of water into the second jug, after that, we fill the first jug with water and get z = ax - by litres of water.
    //
    //Otherwise if 0 <= ax - (b-1)y <= x + y, with 0 <= ax - by <= x+y, we can get y <= ax - (b-1)y.
    //After we get ax - (b-1)y litres of water in the tow jugs, we can fulfill the second jug (and empty it), the amount of water left in the first jug will be z = ax - by.
    
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (z > x + y) return false;
        if (x == 0) return y == z;
        if (y == 0) return x == z;
        int g = gcd(x, y);
        return z % g == 0;
    }
};

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
