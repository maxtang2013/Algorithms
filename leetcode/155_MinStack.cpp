#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int minVal = x;
        if (mMin.size() > 0 && mMin.back() < x) minVal = mMin.back();
        mElements.push_back(x);
        mMin.push_back(minVal);
    }
    
    void pop() {
        if (mElements.empty()) return;
        mMin.pop_back();
        mElements.pop_back();
    }
    
    int top() {
        if (mElements.size() == 0) {
            return INT_MIN;
        }
        return mElements.back();
    }
    
    int getMin() {
        if (mElements.empty()) return INT_MAX;
        return mMin.back();
    }
private:
    vector<int> mElements;
    vector<int> mMin;
};

void Test0()
{
    MinStack S;
    
    S.push(4);
    S.push(3);
    S.push(5);
    
    cout << S.getMin() << endl;
    
    S.pop();
    cout << S.top() << endl;
    
    cout << S.getMin() << endl;
    
    S.pop();
    cout << S.getMin() << endl;
    
    
}

int main()
{
    Test0();
    
    return 0;
}
