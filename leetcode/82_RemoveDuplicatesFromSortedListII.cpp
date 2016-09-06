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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode dummy(head->val + 1);
        dummy.next = head;
        
        ListNode*pprev = &dummy, *prev = pprev->next, *curr = prev->next;
        
        while (curr != NULL) {
            bool dup = false;
            while (curr != NULL && curr->val == prev->val) {
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
                dup = true;
            }
            
            if (!dup) {
                pprev = prev;
                prev = curr;
                curr = curr == NULL ? NULL : curr->next;
            } else {
                pprev->next = curr;
                prev = curr;
                curr = prev ? prev->next : NULL;
            }
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


void Test0() {
    Solution sln;
    ListNode n1(1), n2(1), n3(2), n4(2), n5(2), n6(3), n7(3);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    
    printfLinkedList(sln.deleteDuplicates(&n1));
}

void Test1() {
    Solution sln;
    ListNode n1(1), n2(1), n3(2), n4(3), n5(3), n6(3), n7(3), n8(8);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    
    printfLinkedList(sln.deleteDuplicates(&n1));
}

int main() {
    Test0();
    Test1();
    
    return 0;
}
