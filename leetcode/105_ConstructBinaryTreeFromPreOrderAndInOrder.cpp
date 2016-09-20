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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, preorder.size());
    }
    
private:
    TreeNode* buildTree(const vector<int>& preorder, int pfrom, int pto, const vector<int>& inorder, int from, int to) {
        if (to == from) return NULL;
        if (to == from + 1) {
            return new TreeNode(inorder[from]);
        }
        
        int val = preorder[pfrom];
        int len = 0;
        for (int i = from; i < to; ++i) {
            if (inorder[i] == val) {
                len = i - from;
                break;
            }
        }
        TreeNode* node = new TreeNode(val);
        node->left = buildTree(preorder, pfrom + 1, pfrom + len + 1, inorder, from, from + len);
        node->right = buildTree(preorder, pfrom + len + 1, pto, inorder, from + len + 1, to);
        return node;
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
    
    vector<int> pre = {1, 2, 4, 8, 5, 3, 6, 7};
    vector<int> in = {8, 4, 2, 5, 1, 6, 3, 7};
    
    TreeNode* node = sln.buildTree(pre, in);
    
    printBoard(levelOrder(node));
}

int main()
{
    Test0();
    
    return 0;
}
