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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m == n) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fixed = &dummy;
        ListNode* n1 = &dummy, *prev = NULL, *next = NULL;
        int i = 0;
        while (i < m) {
            n1 = n1->next;
            if (i < m - 1) fixed = fixed->next;
            ++i;
        }
        
        next = n1->next;
        do {
            n1->next = prev;
            prev = n1;
            n1 = next;
            next = n1->next;
            ++i;
        } while (i < n);
        n1->next = prev;
        
        if (fixed->next != NULL) {
            fixed->next->next = next;
        }
        fixed->next = n1;
        return dummy.next;
    }
};

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
    ListNode nodes[] = { {1}, {2}, {3}, {4}, {5} };
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    ListNode *n = sln.reverseBetween(nodes, 2, 4);
    printfLinkedList(n);
}

void Test1()
{
    Solution sln;
    ListNode nodes[] = { {1}, {2}, {3}, {4}, {5} };
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    ListNode *n = sln.reverseBetween(nodes, 2, 5);
    printfLinkedList(n);
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
