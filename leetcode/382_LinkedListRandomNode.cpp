#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : mHead(head) {
        
    }
    
    /** Returns a random node's value. */
    /**
     reservoir sampling
     */
    int getRandom() {
        int i = 1;
        ListNode* curr = mHead;
        ListNode* node = mHead;
        
        while (node != NULL)
        {
            int r = rand() % i;
            if (r >= i - 1)
            {
                curr = node;
            }
            node = node->next;
            ++i;
        }
        return curr->val;
    }
private:
    ListNode *mHead;
};



int main()
{
    // Solution sln;
    return 0;
}
