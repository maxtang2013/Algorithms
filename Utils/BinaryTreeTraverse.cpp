#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class TreeTraversor {
public:
    
    void preorder(TreeNode* root) {
        
    }
    
    void inorder(TreeNode* root) {
        vector<TreeNode*> S;
        TreeNode* n = root;
        
        while (n != NULL || !S.empty()) {
            if (n != NULL) {
                S.push_back(n);
                n = n->left;
            } else {
                n = S.back();
                S.pop_back();
                
                // visit node here!
                cout << n->val << endl;
                
                n = n->right;
            }
        }
    }
    
    void postorder(TreeNode* root) {
        vector<TreeNode*> S;
        
        TreeNode* prev = NULL;
        TreeNode* n = root;
        
        while (n != NULL || !S.empty()) {
            if (n != NULL) {
                S.push_back(n);
                n = n->left;
            } else {
                n = S.back();
                
                if (n->right == NULL || prev == n->right) {
                    
                    // visit node here!
                    cout << n->val << endl;
                    
                    S.pop_back();
                    prev = n;
                    n = NULL;
                } else {
                    n = n->right;
                }
            }
        }
    }
};