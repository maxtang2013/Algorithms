#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* n = root, *prev = NULL;
        vector<TreeNode*> S;
        S.push_back(root);
        
        while (!S.empty()) {
            n = S.back();
            S.pop_back();
            
            if (prev != NULL) {
                prev->left = NULL;
                prev->right = n;
            }
            
            prev = n;
            if (n->right) S.push_back(n->right);
            if (n->left) S.push_back(n->left);
            
        }
    }
};

struct TreeNodeItem {
    TreeNode* node;
    int level;
};

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
    sln.flatten(nodes);
    
    printBoard(levelOrder(nodes));
    
}

int main()
{
    Test0();
    
    return 0;
}
