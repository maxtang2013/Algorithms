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
    /***
     *
     * Treated it too complicated...
     * A recursive solution would be way simpler.
     *
     */
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return NULL;
        TreeNode** nodes = new TreeNode*[n+1];
        int i;
        
        for (i = 1; i <= n; ++i)
            nodes[i] = new TreeNode(0);
        
        for (int i = 1; i < n; ++i)
        {
            if ( i * 2 <= n )
                nodes[i]->left = nodes[i * 2];
            if ( i * 2 + 1 <= n)
                nodes[i]->right = nodes[i * 2 + 1];
        }
        
        vector<TreeNode*> stack;
        TreeNode *node = nodes[1];
        int index = 0;
        while (node != NULL || !stack.empty())
        {
            if (node == NULL)
            {
                node = stack.back();
                stack.pop_back();
                
                node->val = nums[index++];
                node = node->right;
            }
            else
            {
                stack.push_back(node);
                node = node->left;
            }
        }
        
        return nodes[1];
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* toBST(vector<int>& nums, int lower, int upper)
    {
        if (lower > upper) return NULL;
        
        if (lower == upper)
        {
            return new TreeNode(nums[lower]);
        }
        
        int mid = (lower + upper) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = toBST(nums, lower, mid - 1);
        node->right = toBST(nums, mid + 1, upper);
        return node;
    }
};

// Inorder traverse.
void Traverse(TreeNode* root)
{
    vector<TreeNode*> stack;
    if (root == NULL) return;
    
    TreeNode* n = root;
    // stack.push_back(root);
    while (n != NULL || !stack.empty())
    {
        if (n != NULL)
        {
            stack.push_back(n);
            n = n->left;
        }
        else
        {
            n = stack.back();
            printf("%d ", n->val);
            stack.pop_back();
            n = n->right;
        }
    }
    printf("\n");
}


void Test0()
{
    Solution sln;
    vector<int> nums = {0};
    Traverse(sln.sortedArrayToBST(nums));
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1, 3};
    Traverse(sln.sortedArrayToBST(nums));
}

void Test2()
{
    Solution sln;
    vector<int> nums = {3, 5, 8};
    Traverse(sln.sortedArrayToBST(nums));
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
