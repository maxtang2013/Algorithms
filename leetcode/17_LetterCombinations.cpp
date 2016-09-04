#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        mCurrStr.assign(digits.length(), ' ');
        mAns.clear();
        mDigitToChar.clear();
        
        if (digits.empty()) return mAns;
        
        mDigitToChar.resize(10);
        mDigitToChar[2] = {'a', 'b', 'c'};
        mDigitToChar[3] = {'d', 'e', 'f'};
        mDigitToChar[4] = {'g', 'h', 'i'};
        mDigitToChar[5] = {'j', 'k', 'l'};
        mDigitToChar[6] = {'m', 'n', 'o'};
        mDigitToChar[7] = {'p', 'q', 'r', 's'};
        mDigitToChar[8] = {'t', 'u', 'v'};
        mDigitToChar[9] = {'w', 'x', 'y', 'z'};
        
        for (int i = 0; i < digits.length(); ++i) {
            if (digits[i] == '1' || digits[i] == '0') {
                return mAns;
            }
        }
        
        Traverse(0, (int)digits.size(), digits);
        return mAns;
    }
private:
    void Traverse(int i, int n, string& digits) {
        if (i == n) {
            mAns.push_back(mCurrStr);
            return;
        }
        
        vector<char> &chars = mDigitToChar[digits[i] - '0'];
        for (int j = 0; j < chars.size(); ++j) {
            mCurrStr[i] = chars[j];
            Traverse(i+1, n, digits);
        }
    }
    vector<vector<char>> mDigitToChar;
    vector<string> mAns;
    string mCurrStr;
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
}


void Test0()
{
    Solution sln;
    vector<string> ans = sln.letterCombinations("23");
    printVector(ans);
}
void Test1()
{
    Solution sln;
    vector<string> ans = sln.letterCombinations("123");
    printVector(ans);
}

int main()
{
    Test1();
    
    return 0;
}
