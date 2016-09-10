#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int) gas.size();
        int i = 0, j = 0;
        do {
            int sum = gas[i] - cost[i];
            
            j = (i + 1) % n;
            while (sum >= 0 && j != i) {
                sum = sum + (gas[j] - cost[j]);
                j = (j + 1) % n;
            }
            
            if (sum >= 0) return i;
            if (j == i) return -1;
            i = j;
        } while (i != 0);
        return -1;
    }
};

void Test0()
{
    Solution sln;
    vector<int> gas = {4, 3, 8, 1, 2};
    vector<int> cost = {6, 2, 3, 1, 1};
    cout << sln.canCompleteCircuit(gas, cost) << endl;
}

void Test1() {
    Solution sln;
    vector<int> gas = {2, 4};
    vector<int> cost = {3, 4};
    cout << sln.canCompleteCircuit(gas, cost) << endl;
}
int main()
{
    Test0();
    Test1();
    
    return 0;
}
