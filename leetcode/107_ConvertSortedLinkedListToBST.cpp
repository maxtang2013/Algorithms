#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeItem {
    TreeNode* node;
    int level;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* n = head;
        while (n != NULL) {
            n = n->next;
            ++len;
        }
        
        return sortedListToBST(head, len);
    }
    
private:
    TreeNode* sortedListToBST(ListNode* head, int len) {
        if (len == 0) return NULL;
        if (len == 1) {
            return new TreeNode(head->val);
        }
        
        int k = (len + 1) / 2;
        ListNode* n = head;
        for (int i = 1; i < k; ++i) {
            n = n->next;
        }
        TreeNode* tnode = new TreeNode(n->val);
        
        tnode->left = sortedListToBST(head, k - 1);
        tnode->right = sortedListToBST(n->next, len - k);
        
        return tnode;
    }
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}
template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}

void printfLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    
    vector<TreeNodeItem> S;
    TreeNodeItem item = {root, 0};
    S.push_back(item);
    while (!S.empty()) {
        item = S.back();
        S.pop_back();
        
        if (item.level >= ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[item.level].push_back(item.node->val);
        
        if (item.node->right != NULL) {
            TreeNodeItem item1 = {item.node->right, item.level + 1};
            S.push_back(item1);
        }
        if (item.node->left != NULL) {
            TreeNodeItem item1 = {item.node->left, item.level + 1};
            S.push_back(item1);
        }
    }
    return ans;
}

void TreeNodeTest()
{
    Solution sln;
    
    //        1
    //    2      3
    //  4   5  6   7
    //8
    
    TreeNode nodes[] = {1, 2, 3, 4, 5, 6,7 ,8};
    int len = sizeof(nodes) / sizeof(TreeNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i*2+2<len)
            nodes[i].right = nodes + (i*2+2);
    }
}

void Test0()
{
    Solution sln;
    ListNode nodes[] = {1, 2, 3, 4, 5, 6,7 ,8};
    for (int i = 0; i < sizeof(nodes) / sizeof(ListNode) - 1; ++i) {
        nodes[i].next = &nodes[i+1];
    }
    
    TreeNode* t = sln.sortedListToBST(nodes);
    printBoard(levelOrder(t));
}

int main()
{
    Test0();
    
    return 0;
}
