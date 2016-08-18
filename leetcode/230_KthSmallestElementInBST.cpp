#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        countNodes(root);
        
        return kthSmallestInner(root, k);
    }
    
    int kthSmallestInner(TreeNode* node, int k)
    {
        if (node->left != NULL)
        {
            int cnt = mCountMap[node->left];
            
            if (cnt >= k)
                return kthSmallestInner(node->left, k);
            
            k -= cnt;
        }
        
        if (k == 1)
        {
            return node->val;
        }
        --k;
        
        return kthSmallestInner(node->right, k);
    }
    
    
    
private:
    int countNodes(TreeNode* node)
    {
        int cnt = 1;
        if (node->left != NULL)
            cnt += countNodes(node->left);
        if (node->right != NULL)
            cnt += countNodes(node->right);
        mCountMap[node] = cnt;
        return cnt;
    }

    std::map<TreeNode*, int> mCountMap;
    TreeNode* mRoot;
};

void Test0()
{
    Solution sln;
    TreeNode node(3);
    printf("%d\n", sln.kthSmallest(&node, 1));
}


void Test1()
{
    Solution sln;
    TreeNode n1(2), n2(1), n3(3);
    n1.left = &n2;
    n1.right = &n3;
    printf("%d\n", sln.kthSmallest(&n1, 3));
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
