#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class ExpressionEvaluator {
public:
    int eval (string s) {
        s = "(" +  s + ")";
        int n = (int) s.length();
        int number = 0, result = 0;
        
        mOperands.clear();
        mOps.clear();
        mHaveConsumedDigits = false;
        
        for (int i = 0; i < n; ++i) {
            if (!isdigit(s[i]) && mHaveConsumedDigits) {
                mOperands.push_back(number);
                number = 0;
                mHaveConsumedDigits = false;
                
                consumeMulDiv();
            }
            
            if (s[i] == ')') {
                
                // Consume all ops up to the matching '('.
                int j = (int) mOps.size() - 1;
                for (; j >= 0 && mOps[j] != '('; --j);
                
                int nummOperands = (int)mOps.size() - j;
                int res = mOperands[mOperands.size() - nummOperands];
                size_t gap = mOperands.size() - mOps.size();
                
                while (++j < mOps.size()) {
                    int v = mOperands[gap + j];
                    res += mOps[j] == '+' ? v : -v;
                }
                
                while (nummOperands-- > 0) {
                    mOperands.pop_back();
                    mOps.pop_back();
                }
                mOperands.push_back(res);
                
                // There might be a '*' or '/' before '(', consume it.
                consumeMulDiv();
                
                continue;
            }
            
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
                mHaveConsumedDigits = true;
            } else if (s[i] != ' ') {
                mOps.push_back(s[i]);
            }
        }
        
        result = mOperands[0];
        
        return result;
    }
    
private:
    
    void consumeMulDiv() {
        if (!mOps.empty() && (mOps.back() == '*' || mOps.back() == '/')) {
            int v1 = mOperands.back(); mOperands.pop_back();
            int v2 = mOperands.back(); mOperands.pop_back();
            
            int v = mOps.back() == '*' ? v1 * v2 : (v2 / v1);
            
            mOperands.push_back(v);
            mOps.pop_back();
        }
    }
    
private:
    vector<int> mOperands;
    vector<char> mOps;
    bool mHaveConsumedDigits;
};

class Solution {
public:
    
    int evalIII(string s) {
        ExpressionEvaluator evaluator;
        return evaluator.eval(s);
    }
    
    
    // expression with '+','-','*','/'
    // The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
    // The integer division should truncate toward zero.
    int eval(string s) {
        s = s + " ";
        vector<int> operands;
        vector<char> ops;
        int number = 0;
        int n = (int) s.length();
        bool prevDigit = false;
        
        for (int i = 0; i < n; ++i) {
            if (!isdigit(s[i]) && prevDigit) {
                operands.push_back(number);
                number = 0;
                prevDigit = false;
                
                if (!ops.empty() && (ops.back() == '*' || ops.back() == '/')) {
                    int v1 = operands.back(); operands.pop_back();
                    int v2 = operands.back(); operands.pop_back();
                    int v = ops.back() == '*' ? v2 * v1 : v2 / v1;
                    operands.push_back(v);
                    ops.pop_back();
                }
            }
            
            if (isdigit(s[i])) {
                prevDigit = true;
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] != ' ') {
                ops.push_back(s[i]);
            }
        }
        
        int result = operands[0];
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == '+') {
                result += operands[i+1];
            } else {
                result -= operands[i+1];
            }
        }
        return result;
    }
    
    // expression with '+','-','(',')',' ',and digits.
    int calculate(string s) {
        vector<int> Stack = {1, 1};
        int n = (int)s.length();
        int number = 0;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (!isdigit(s[i]) && number !=  0) {
                result += Stack.back() * number;
                number = 0;
                Stack.pop_back();
            }
            
            if (s[i] == '+') {
                Stack.push_back(Stack.back());
            } else if (s[i] == '-') {
                Stack.push_back(-Stack.back());
            } else if (s[i] == '(') {
                Stack.push_back(Stack.back());
            } else if (s[i] == ')') {
                Stack.pop_back();
            } else if (isdigit(s[i])) {
                number = number * 10 + (s[i]-'0');
            }
        }
        
        result += Stack.back() * number;
        return result;
    }
    
};

void Test0()
{
    Solution sln;
    cout << sln.calculate("(1+(4+5+2)-3)+(6+8)") << endl<<endl;
    cout << sln.calculate(" 2-1 + 2 ") << endl;
    cout << sln.calculate("2-(5-6)") << endl;
}

void Test1()
{
    Solution sln;
    cout << sln.eval(" 3 / 2 - 3 ") << endl;
    cout << sln.eval("0") << endl;
    cout << sln.eval("  3- 3 / 2 *4") << endl;
    cout << sln.eval("3-4*5-1*2/4+1-4+1+3/2*4") << endl;
}

void Test2()
{
    Solution sln;
    cout << sln.evalIII("4*(4-2/(3-1))") << endl;
     cout << sln.evalIII("4/2+3*(4-2/(3-1))") << endl;
     cout << sln.evalIII("(1-4)*6/3*(4-2/(3-1))") << endl;
}

int main()
{
//    Test0();
    Test1();
    Test2();
    
    return 0;
}
