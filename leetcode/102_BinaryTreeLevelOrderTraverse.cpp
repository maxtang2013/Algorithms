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

struct TreeNodeItem {
    TreeNode* node;
    int level;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<TreeNodeItem> S;
        TreeNodeItem item = {root, 0};
        int maxHeight = -1;
        
        S.push_back(item);
        while (!S.empty()) {
            item = S.back();
            S.pop_back();
            
            maxHeight = max(maxHeight, item.level);
            
            if (item.node->right != NULL) {
                TreeNodeItem item1 = {item.node->right, item.level + 1};
                S.push_back(item1);
            }
            if (item.node->left != NULL) {
                TreeNodeItem item1 = {item.node->left, item.level + 1};
                S.push_back(item1);
            }
        }
        
        return maxHeight + 1;
    }
};


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
    
    printBoard(sln.levelOrder(nodes));
}

int main()
{
    Test0();
    
    return 0;
}
