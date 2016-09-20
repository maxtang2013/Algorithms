#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = (int) digits.size();
        int i = n - 1;
        int d = 0;
        
        while (carry > 0 && i >= 0) {
            d = digits[i] + 1;
            if (d > 9){
                d -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            digits[i] = d;
            --i;
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<int> digits = {9, 9};
    
    printVector(sln.plusOne(digits));
}

void Test1() {
    Solution sln;
    vector<int> digits = {0};
    
    printVector(sln.plusOne(digits));
}
int main()
{
    Test0();
    Test1();
    
    return 0;
}
