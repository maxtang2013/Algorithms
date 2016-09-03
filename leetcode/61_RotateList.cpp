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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head, *p=head;
        
        int n = 0;
        while (p != NULL) {
            p = p->next;
            ++n;
        }
        if (n == 0) return NULL;
        k = k % n;
        
        if (k == 0) return head;
        p = head;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
        }
        
        while (tail->next != NULL) {
            tail = tail->next;
            p = p->next;
        }
        
        tail->next = head;
        head = p->next;
        p->next = NULL;
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
    
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
    printfLinkedList(sln.rotateRight(&n1, 2));
}

void Test1()
{
    Solution sln;
    
    ListNode n1(1), n2(2);
    n1.next = &n2;
    
    printfLinkedList(sln.rotateRight(&n1, 1));
}

void Test2()
{
    Solution sln;
    
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
   
    printfLinkedList(sln.rotateRight(&n1, 8));
}

void Test3()
{
    Solution sln;
    
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    //n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n5;
    
    printfLinkedList(sln.rotateRight(&n1, 8));
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
