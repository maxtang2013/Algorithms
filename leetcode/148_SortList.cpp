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
    // Merge sort
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = sortList(slow->next);
        slow->next = NULL;
        slow = sortList(head);
        
        // Merge
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (slow != NULL && fast != NULL) {
            if (slow->val <= fast->val) {
                curr->next = slow;
                curr = slow;
                slow = slow->next;
            } else {
                curr->next = fast;
                curr = fast;
                fast = fast->next;
            }
        }
        if (slow != NULL) {
            curr->next = slow;
        }
        if (fast != NULL) {
            curr->next = fast;
        }
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
    
    ListNode nodes[] = {1, 5, 3, 2, 10, 6, 7 ,8, 9};
    int len = sizeof(nodes) / sizeof(ListNode);
    for (int i = 0; i < len-1; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    printfLinkedList(sln.sortList(nodes));
}

void Test1()
{
    Solution sln;
    
    ListNode nodes[] = {-1, 5, 3, 2, 10, 6, 7 ,8, 9, 21, 15, 18, 9, 8, 7};
    int len = sizeof(nodes) / sizeof(ListNode);
    for (int i = 0; i < len-1; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    printfLinkedList(sln.sortList(nodes));
}


int main()
{
    Test0();
    Test1();
    
    return 0;
}
