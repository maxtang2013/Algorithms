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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;
        
        while (node != NULL) {
            ListNode* tail = node;
            
            for (int i = 1; tail != NULL && i < k; ++i) {
                tail = tail->next;
            }
            
            if (tail != NULL) {
                ListNode* prev = node;
                if (prevTail != NULL)
                    prevTail->next = tail;
                
                if (newHead == NULL) newHead = tail;
                
                ListNode* curr = node;
                prevTail = node;
                ListNode* nextSection = tail->next;
                
                ListNode* reversedHead = node;
                curr = node->next;
                node->next = NULL;
                
                for (int i = 1; i < k; ++i)
                {
                    ListNode* next = curr->next;
                    curr->next = reversedHead;
                    reversedHead = curr;
                    curr = next;
                }

                node = nextSection;
            } else {
                if (prevTail != NULL) {
                    prevTail->next = node;
                }
                if (newHead == NULL) newHead = node;
                node = NULL;
            }
        }
        return newHead;
    }
};

void Test0()
{
    Solution sln;
    ListNode k[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < 8; ++i) {
        k[i].next = &k[i + 1];
    }
    
    ListNode* l = sln.reverseKGroup(&k[0], 3);
    
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");

}

void Test1()
{
    Solution sln;
    ListNode k[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < 8; ++i) {
        k[i].next = &k[i + 1];
    }
    
    ListNode* l = sln.reverseKGroup(&k[0], 4);
    
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    
}

void Test2()
{
    Solution sln;
    ListNode k[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < 8; ++i) {
        k[i].next = &k[i + 1];
    }
    
    ListNode* l = sln.reverseKGroup(&k[0], 1);
    
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    
}


void Test3()
{
    Solution sln;
    ListNode k[] = {1};
    
    ListNode* l = sln.reverseKGroup(&k[0], 2);
    
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
