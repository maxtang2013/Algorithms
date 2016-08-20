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
    int rob(TreeNode* root) {
        TreeNode super(0);
        super.left = root;
        
        return maxRobberyWithoutSelf(&super);
    }
    
private:
    int maxRobberyWithSelf(TreeNode* node)
    {
        if (maxWithSelf.count(node) > 0)
        {
            return maxWithSelf[node];
        }
        
        int cnt = node->val;
        if (node->left != NULL)
        {
            cnt += maxRobberyWithoutSelf(node->left);
        }
        if (node->right != NULL)
        {
            cnt += maxRobberyWithoutSelf(node->right);
        }
        maxWithSelf[node] = cnt;
        return cnt;
    }
    
    int maxRobberyWithoutSelf(TreeNode* node)
    {
        if (maxWithoutSelf.count(node) > 0)
        {
            return maxWithoutSelf[node];
        }
        
        int cnt = 0;
        if (node->left != NULL)
        {
            cnt += max(maxRobberyWithoutSelf(node->left), maxRobberyWithSelf(node->left));
        }
        
        if (node->right != NULL)
        {
            cnt += max(maxRobberyWithoutSelf(node->right), maxRobberyWithSelf(node->right));
        }
        maxWithoutSelf[node] = cnt;
        return cnt;
    }
    
private:
    map<TreeNode*, int> maxWithSelf;
    map<TreeNode*, int> maxWithoutSelf;
};

void Test0()
{
//    3
//    / \
//    4   5
//    / \   \
//    1   3   1
    TreeNode r0(3), r1(4), r2(5), r3(1), r4(3), r5(1);
    r0.left = &r1; r0.right = &r2;
    r1.left = &r3; r1.right = &r4; r2.right = &r5;
    Solution sln;
    printf("%d\n", sln.rob(&r0));
}

void Test1()
{
//     3
//    / \
//   2   3
//    \   \
//     3   1
    TreeNode r0(3), r1(2), r2(3), r4(3), r5(1);
    r0.left = &r1; r0.right = &r2;
    r1.right = &r4; r2.right = &r5;
    Solution sln;
    printf("%d\n", sln.rob(&r0));
}

int main()
{
    Test0();
    Test1();
    return 0;
}
