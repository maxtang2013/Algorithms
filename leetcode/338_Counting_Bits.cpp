#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        int cnt = 0;
        int i;
        
        vector<int> cnts;
        cnts.resize(num + 1);
        
        cnts[0] = 0;
        for (i = 1; i <= num; ++i)
        {
            cnts[i] = cnts[i & (i - 1)] + 1;
        }
        return cnts;
    }
};

void printVector(const vector<int>& list)
{
    
    for (int i = 0; i < list.size(); ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}


int main()
{
    Solution sln;
    printVector(sln.countBits(20));
}