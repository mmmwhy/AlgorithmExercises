#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) {
        val = x, left = NULL, right = NULL;
    }
};

void preOrder(TreeNode *root) {
    if (!root) return;
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val;
    inOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val;
}

int main() {
    TreeNode *a = &TreeNode(1);
    TreeNode *b = &TreeNode(2);
    TreeNode *c = &TreeNode(3);
    TreeNode *d = &TreeNode(4);
    TreeNode *e = &TreeNode(5);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    preOrder(a);
    cout << endl;
    inOrder(a);
    cout << endl;
    postOrder(a);
}