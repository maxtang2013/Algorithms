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

void printfLinkedList(ListNode* head);

class Solution {
public:
    
    ListNode* merge(ListNode* slow, ListNode* fast) {
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
    
    ListNode* getListTail(ListNode* node, int k) {
        for (int i = 0; node->next != NULL && i < k; ++i) {
            node = node->next;
        }
        return node;
    }
    
    ListNode* bottomUpMergeSort(ListNode* head) {
        int len = 1;
        bool merged = true;
        while (merged) {
            ListNode* nextPair = head;
            ListNode* mergedList = NULL;
            ListNode* prevTail = NULL;
            ListNode* newHead = NULL;
            
            merged = false;
            
            while (nextPair != NULL) {
                ListNode* secondList = nextPair, *firstList = nextPair;
                ListNode* tail;
                
                // find the tail of the first list to merge.
                tail = getListTail(firstList, len - 1);
                if (tail->next != NULL) {
                    secondList = tail->next;
                    tail->next = NULL;
                    
                    // find the tail of the second list
                    tail = getListTail(secondList, len - 1);
                    
                    nextPair = tail->next;
                    tail->next = NULL;
                    
                    merged = true;
                    
                    mergedList = merge(firstList, secondList);
                } else {
                    mergedList = firstList;
                    nextPair = NULL;
                }
                
                if (newHead == NULL) newHead = mergedList;
                
                if (prevTail != NULL) {
                    prevTail->next = mergedList;
                } else {
                    prevTail = mergedList;
                }
                
                while (prevTail->next != NULL) {
                    prevTail = prevTail->next;
                }
            }
            
            if (newHead != NULL) head = newHead;
            // cout << "Round: "<< len <<  endl;
            printfLinkedList(head);
            len = len << 1;
        }
        
        return head;
    }
    
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
    
    // printfLinkedList(sln.bottomUpMergeSort(nodes));
    //printfLinkedList(sln.sortList(nodes));
}

void Test1()
{
    Solution sln;
    
    ListNode nodes[] = {-1, 5, 3, 2, 10, 6, 7 ,8, 9, 21, 15, 18, 9, 8, 7};
    int len = sizeof(nodes) / sizeof(ListNode);
    for (int i = 0; i < len-1; ++i) {
        nodes[i].next = nodes + i + 1;
    }
    
    // printfLinkedList(sln.sortList(nodes));
    
    printfLinkedList(sln.bottomUpMergeSort(nodes));
}


int main()
{
    Test0();
    Test1();
    
    return 0;
}
