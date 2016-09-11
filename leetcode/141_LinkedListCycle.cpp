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

int main()
{
    Test0();
    Test1();
    
    return 0;
}
