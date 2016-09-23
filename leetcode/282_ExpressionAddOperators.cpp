#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        mTarget = target;
        mNum = num;
        mNumLength = num.length();
        mAns.clear();
        
        for (int i = 1; i <= mNumLength; ++i) {
            string s = mNum.substr(0, i);
            int operand = stol(s);
            
            if (to_string(operand) != s) continue;
            dfs(i, s, operand, operand, '+');
        }
        return mAns;
    }

private:
    int mTarget;
    string mNum;
    int mNumLength;
    vector<string> mAns;

    void dfs(int i, const string& currExpr, int prevOperand, int currExprValue, char prevOp) {
        if (i == mNumLength) {
            if (mTarget == currExprValue) {
                mAns.push_back(currExpr);
            }
            return;
        }
        
        for (int j = i + 1; j <= mNumLength; ++j) {
            string s = mNum.substr(i, j-i);
            int operand = stol(s);
            
            if (to_string(operand) != s) continue;
            
            dfs(j, currExpr + "+" + s, operand, currExprValue + operand, '+');
            dfs(j, currExpr + "-" + s, operand, currExprValue - operand, '-');
            if (prevOp == '-') {
                dfs(j, currExpr + "*" + s, prevOperand * operand, currExprValue + prevOperand - prevOperand * operand, prevOp);
            } else if (prevOp == '+') {
                dfs(j, currExpr + "*" + s, prevOperand * operand, currExprValue - prevOperand + prevOperand * operand, prevOp);
            }
        }
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
    
    printVector( sln.addOperators("3456237490", 9191) );
    
    printVector( sln.addOperators("123", 6) );
    
    // cout << 3+4-56*2*3*7*4+9*0 << endl;
}

int main()
{
    Test0();
    
    return 0;
}
