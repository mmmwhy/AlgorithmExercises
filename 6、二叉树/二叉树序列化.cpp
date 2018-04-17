//题目：https://www.nowcoder.com/practice/e3a3a1a956914d8ca5688ea47a5cf9c9
//思路：递归来做，每个节点"("+左子树+右子树+")"
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
}; 

class TreeToSequence {
public:
    string toSequence(TreeNode* root) {
        // write code here
        if (root == NULL) return "";
        return "(" + toSequence(root->left) + toSequence(root->right) + ")";;
    }
};

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
    TreeToSequence test;
    cout << test.toSequence(a);
    return 0;
}