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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        
        ListNode* fast = head->next, *slow = head, *next;
        
        if (fast == NULL) return;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            if (fast->next->next == NULL) fast = fast->next;
            else fast = fast->next->next;
        }
        
        // reverse the last half
        next = slow->next;
        while (next != fast) {
            slow->next = next->next;
            next->next = fast->next;
            fast->next = next;
            next = slow->next;
        }
        slow->next = NULL;
        
        slow = head;
        while (fast != NULL) {
            ListNode* tmp = fast->next;
            next = slow->next;
            slow->next = fast;
            fast->next = next;
            slow = next;
            fast = tmp;
        }
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
    
    ListNode nodes[] = {1, 2, 3, 4, 5, 6,7 ,8, 9};
    for (int i = 0; i < 8; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    sln.reorderList(nodes);
    
    printfLinkedList(nodes);
}

void Test1()
{
    Solution sln;
    
    ListNode nodes[] = {1};
    for (int i = 0; i < 0; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    sln.reorderList(nodes);
    
    printfLinkedList(nodes);
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
