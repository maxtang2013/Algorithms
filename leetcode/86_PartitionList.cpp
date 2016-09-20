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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL, *head2 = NULL, *curr1 = NULL, *curr2 = NULL;
        
        while (head != NULL) {
            if (head->val < x) {
                if (head1 == NULL) {
                    head1 = curr1 = head;
                } else {
                    curr1->next = head;
                    curr1 = head;
                }
            } else {
                if (head2 == NULL) {
                    head2 = curr2 = head;
                } else {
                    curr2->next = head;
                    curr2 = head;
                }
            }
            head = head->next;
        }
        
        if (curr1 != NULL) {
            curr1->next = head2;
            head = head1;
        }
        
        if (curr2 != NULL) {
            curr2->next = NULL;
            if (head == NULL) {
                head = head2;
            }
        }
        
        return head;
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
    ListNode n1(4), n2(5), n3(1), n4(6), n5(2), n6(3);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    ListNode* n = sln.partition(&n1, 3);
    printfLinkedList(n);
}

int main()
{
    Test0();
    
    return 0;
}
