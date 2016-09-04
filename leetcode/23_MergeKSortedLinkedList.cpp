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

struct Comp {
    bool operator()(ListNode* a, ListNode* b) {
        if (a == NULL) return true;
        if (b == NULL) return false;
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> Q;
        ListNode* head = NULL, *tail = NULL;
        int k = (int) lists.size();
        
        for (int i = 0; i < k; ++i) {
            Q.push(lists[i]);
        }
        
        while (!Q.empty()) {
            ListNode* node = Q.top();
            Q.pop();
            if (node == NULL) {
                continue;
            }
            Q.push(node->next);
            
            if (tail == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};

void Test0()
{
    Solution sln;
    ListNode k1(3), k2(5), k3(5);
    ListNode t1(4), t2(5);
    ListNode m1(0), m2(2), m3(6);
    
    k1.next = &k2;
    k2.next = &k3;
    t1.next = &t2;
    m1.next = &m2;
    m2.next = &m3;
    
    vector<ListNode*> lists = {&k1, &t1, &m1};
    ListNode* l = sln.mergeKLists(lists);
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main()
{
    Test0();
    
    return 0;
}
