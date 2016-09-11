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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
        } while (fast != slow && fast != NULL && slow != NULL);
        return fast != NULL && slow != NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
        } while (fast != slow && fast != NULL && slow != NULL);
        
        if (fast == NULL || slow == NULL) return NULL;
        
        //                           ____________________________
        //                          |                            |
        //                         \|/                           |
        //  head --> n1 --> ... --> c0 --> ... --> cj --> ... --> ce
        //  \_______   L __________/
        //
        //  If pointer 'fast' and pointer 'slow' meets at 'cj' after k steps, it needs L steps to move 'slow' from 'head' to 'c0',
        //  it needs x steps to move pointer 'slow' from 'c0' to 'cj', then we have
        //    (1)     L + x = k
        //    (2)     L + x + R = k * 2, R is length of the cycle.
        //  We can conclude that,
        //            L = R - x
        //  Note that it also needs 'R - x' steps to move pointer 'slow' from 'cj' to 'c0'.
        
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        return head;

//        // My original O(n^2) solution.
//        while (true) {
//            if (fast == slow) slow = slow->next;
//            
//            while (slow != head && slow != fast) {
//                slow = slow->next;
//            }
//            
//            if (slow == head) break;
//            head = head->next;
//        }
//        return head;
    }
};

void Test0()
{
    Solution sln;
    
    ListNode nodes[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    cout << sln.hasCycle(nodes) << endl;
}

void Test1()
{
    Solution sln;
    
    ListNode nodes[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    nodes[4].next = nodes + 2;
    cout << sln.hasCycle(nodes) << endl;
}

void Test2()
{
    Solution sln;
    
    ListNode nodes[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    nodes[4].next = nodes + 2;
    ListNode* n = sln.detectCycle(nodes);
    if (n != NULL) {
        cout << n->val << endl;
    } else
        cout << "NULL" << endl;
}


int main()
{
//    Test0();
//    Test1();
    
    Test2();
    
    return 0;
}
