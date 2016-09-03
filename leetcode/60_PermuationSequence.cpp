#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> permNum(10, 1);
        vector<int> nums(n);
        
        for (int i = 1; i <= n; ++i) {
            nums[i-1] = i;
        }
        --k;
        
        for (int i = 1; i < 10; ++i) {
            permNum[i] = permNum[i-1] * i;
        }
        
        string ans;
        for (int i = n-1; i > 0; --i) {
            int x = 0;
            if (k >= permNum[i]) {
                x = k / permNum[i];
                k = k % permNum[i];
            }
            
            ans.append(1, '0' + nums[x]);
            nums.erase(nums.begin() + x);
        }
        
        ans.append(1, '0' + nums[0]);
        
        return ans;
    }
    
private:
    
};

void Test0()
{
    Solution sln;
    
    cout << sln.getPermutation(1, 1) << endl;
}

void Test1()
{
    Solution sln;
    
    cout << sln.getPermutation(3, 6) << endl;
}

void Test2()
{
    Solution sln;
    
    cout << sln.getPermutation(4, 6) << endl;
}

void Test3()
{
    Solution sln;
    
    cout << sln.getPermutation(5, 100) << endl;
}


int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
