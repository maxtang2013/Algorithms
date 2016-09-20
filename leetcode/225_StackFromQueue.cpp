#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        Q.push(x);
        
        for (int i = 0; i < Q.size() - 1; ++i) {
            int v = Q.front();
            Q.pop();
            Q.push(v);
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        Q.pop();
    }
    
    // Get the top element.
    int top() {
        return Q.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
private:
    queue<int> Q;
};

void Test0()
{
    Stack S;
    
    S.push(5);
    cout << S.top() << endl;
    
    S.push(4);
    cout << S.top() << endl;
    
    S.pop();
    
    cout << S.top() << endl;
    S.push(9);
    S.push(8);
    S.push(6);
    cout << S.top() << endl;
    S.pop();
    cout << S.top() << endl;
    
    S.pop();
    cout << S.top() << endl;
}

void Test1() {
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    
    cout << S.top() << endl;
    S.pop();
    cout << S.top() << endl;
    S.pop();
    cout << S.top() << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
