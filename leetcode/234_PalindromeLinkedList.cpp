#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode *fast = head->next, *slow = head, *prev = NULL, *next = NULL;
        bool haveMismatch = false;
        
        // reverse while iterating
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        bool oddNum = fast == NULL;
        fast = slow->next;
        
        slow->next = prev;
        prev = fast;
        
        if (oddNum) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        while (slow != NULL) {
            if (slow->val != fast->val) haveMismatch = true;
            
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
            
            fast = fast->next;
        }
        
        return !haveMismatch;
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
template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}

void printfLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


void Test0()
{
    Solution sln;
    ListNode ns[] = {{1}, {2}, {3}, {4}, {3}, {1}, {1}};
    int len = sizeof(ns) / sizeof(ListNode);
    for (int i = 0; i < len-1; ++i) {
        ns[i].next = ns + i + 1;
    }
    cout << sln.isPalindrome(ns) << endl;
    printfLinkedList(ns);
    cout << endl;
}

int main()
{
    Test0();
    
    return 0;
}
