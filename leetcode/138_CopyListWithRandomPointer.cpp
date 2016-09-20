#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    
    RandomListNode* copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        RandomListNode* curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = next;
            
            curr = next;
        }
        
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        RandomListNode* newHead = head->next, *newPrev = newHead;
        RandomListNode* prev = head;
        curr = head->next->next;
        while (curr != NULL) {
            prev->next = curr;
            newPrev->next = curr->next;
            
            prev = curr;
            newPrev = curr->next;
            
            curr = curr->next->next;
        }
        prev->next = NULL;
        newPrev->next = NULL;
        return newHead;
    }
    
    RandomListNode* copyRandomListWithMap(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* n = head;
        RandomListNode* newHead = getListNode(n->label);
        RandomListNode* curr = newHead;
        
        while (n != NULL) {
            if (n->next != NULL) {
                curr->next = getListNode(n->next->label);
            }
            if (n->random != NULL) {
                curr->random = getListNode(n->random->label);
            }
            n = n->next;
            curr = curr->next;
        }
        return newHead;
    }
private:
    
    RandomListNode* getListNode(int label) {
        RandomListNode* node = NULL;
        if (mLabelToNode.count(label) > 0) {
            node = mLabelToNode[label];
        } else {
            mLabelToNode[label] = node = new RandomListNode(label);
        }
        return node;
    }
    
    unordered_map<int, RandomListNode*> mLabelToNode;
};

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
