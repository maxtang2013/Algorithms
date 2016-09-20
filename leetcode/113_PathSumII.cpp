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
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        mAns.clear();
        if (root == NULL) return mAns;
        
        traverse(root, sum);
        return mAns;
    }
    
private:

    void traverse(TreeNode* root, int sum) {
        mPath.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val)
                mAns.push_back(mPath);
            mPath.pop_back();
            return;
        }
        
        if (root->left != NULL)
            traverse(root->left, sum - root->val);
        if (root->right != NULL)
            traverse(root->right, sum - root->val);
        
        mPath.pop_back();
    }
    vector<vector<int>> mAns;
    vector<int> mPath;
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
    printBoard(sln.pathSum(nodes, 8));
}

int main()
{
    Test0();
    
    return 0;
}
