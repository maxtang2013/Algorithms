
#include <iostream>

#define RED 0
#define BLACK 1

struct RBTreeNode {
    RBTreeNode *parent;
    RBTreeNode *left, *right;
    int color;
    int val;
};


RBTreeNode* grandparent(RBTreeNode* node) {
    if (node->parent == NULL) return NULL;
    return node->parent->parent;
}

RBTreeNode* uncle(RBTreeNode* node) {
    RBTreeNode* g = grandparent(node);
    if (g == NULL) return NULL;
    
    if (node->parent == g->left) return g->right;
    else return g->left;
}

void insert_case1(struct RBTreeNode*);
void insert_case2(struct RBTreeNode*);
void insert_case3(struct RBTreeNode*);
void insert_case4(struct RBTreeNode*);
void insert_case5(struct RBTreeNode*);
void rotate_left(struct RBTreeNode* n);
void rotate_right(struct RBTreeNode* n);

void insert(struct RBTreeNode*& root, int val) {
    if (root == NULL) {
        root = new RBTreeNode(val);
        insert_case1(root);
    } else {
        
    }
}

void insert_case1(struct RBTreeNode*& node) {
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(n);
}

void insert_case2(struct RBTreeNode *n)
{
    if (n->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}

void insert_case3(struct RBTreeNode *n)
{
    struct RBTreeNode *u = uncle(n), *g;
    
    if ((u != NULL) && (u->color == RED)) {
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}

void insert_case4(struct RBTreeNode *n)
{
    struct RBTreeNode *g = grandparent(n);
    
    if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);
        
        /*
         * rotate_left can be the below because of already having *g =  grandparent(n)
         *
         * struct node *saved_p=g->left, *saved_left_n=n->left;
         * g->left=n;
         * n->left=saved_p;
         * saved_p->right=saved_left_n;
         *
         * and modify the parent's nodes properly
         */
        
        n = n->left;
        
    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);
        
        /*
         * rotate_right can be the below to take advantage of already having *g =  grandparent(n)
         *
         * struct node *saved_p=g->right, *saved_right_n=n->right;
         * g->right=n; 
         * n->right=saved_p;
         * saved_p->left=saved_right_n;
         * 
         */
        
        n = n->right; 
    }
    insert_case5(n);
}

void insert_case5(struct RBTreeNode *n)
{
    struct RBTreeNode *g = grandparent(n);
    
    n->parent->color = BLACK;
    g->color = RED;
    if (n == n->parent->left)
        rotate_right(g);
    else
        rotate_left(g);
}

void rotate_left(struct RBTreeNode* n) {
    
}

void rotate_right(struct RBTreeNode* n) {
    
}


