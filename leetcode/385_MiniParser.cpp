#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {
        mIsInteger = false;
    }
    // Constructor initializes a single integer.
    NestedInteger(int value) {
        mIsInteger = true;
        mValue = value;
    }
    
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {  return mIsInteger; }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return mValue; }
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        mValue = value;
        mIsInteger = true;
    }
    
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        mList.push_back(ni);
        mIsInteger = false;
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return mList;
    }
    
    string toString() {
        if (mIsInteger) return to_string(mValue);
        string val = "[";
        int i = 0;
        for (NestedInteger ni : mList) {
            if (i++ > 0)
                val += ",";
            val += ni.toString();
        }
        val += "]";
        return val;
    }
    
private:
    bool mIsInteger;
    int mValue;
    vector<NestedInteger> mList;
};

class Solution {
public:
    
    NestedInteger deserialize(string s) {
        NestedInteger ni;
        if (s[0] == '[') {
            int i = 1;
            while (i < s.length() - 1) {
                if ( s[i] == '[' ) {
                    int cnt = 1;
                    for (int j = i + 1; j < s.length() - 1; ++j) {
                        if (s[j] == ']') --cnt;
                        if (s[j] == '[') ++cnt;
                        if (cnt == 0) {
                            NestedInteger inner = deserialize(s.substr(i, j+1-i));
                            ni.add(inner);
                            i = j + 2;
                            break;
                        }
                    }
                } else {
                    int j = i+1;
                    while (s[j] >= '0' && s[j] <= '9') ++j;
                    
                    ni.add(deserialize(s.substr(i, j-i)));
                    i = j + 1;
                }
            }
        } else {
            int val = atoi(s.c_str());
            ni.setInteger(val);
        }
        return ni;
    }
    
    
    NestedInteger deserialize1(string s) {
        vector<NestedInteger> Stack;
        int n = (int)s.length(), i = 0;
        
        while ( i < n ) {
            if (s[i] == ',') {
                ++i;
            } else if (s[i] == '-' || isdigit(s[i])) {
                int j = i + 1;
                while (isdigit(s[j])) ++j;
                
                int val = atoi(s.substr(i, j-i).c_str());
                NestedInteger ni(val);
                
                if (Stack.empty())
                    Stack.push_back(ni);
                else
                    Stack[Stack.size()-1].add(ni);
                i = j;
            } else if (s[i] == '[') {
                NestedInteger ni;
                Stack.push_back(ni);
                ++i;
            } else { // s[i] == ']'
                if (Stack.size() > 1) {
                    // Add to parent when child's been poped, because parents store copies of children, not references.
                    NestedInteger ni = Stack.back();
                    Stack.pop_back();
                    Stack[Stack.size()-1].add(ni);
                }
                
                ++i;
            }
        }
        return Stack.back();
    }
};

void Test0()
{
    Solution sln;
    cout << sln.deserialize1("[[0],6,[3,[4,5,6,7]]").toString() << endl;
    cout << sln.deserialize1("[-1]").toString() << endl;
    cout << sln.deserialize1("[[],[[[[]],-4],[[[]],[0],[[]]]]]").toString() << endl;
 //                           [[],[[[[]]],-4],[[[]]],[0],[[]]]
 //                           [[],[[[[]],-4],[[[]],[0],[[]]]]]
    
    cout << sln.deserialize("[-1]").toString() << endl;
}

int main()
{
    Test0();
    
    return 0;
}
