//题目：https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

int TreeDepth(TreeNode* pRoot,int deep)
{
    if (pRoot == NULL) return deep;
    return max(TreeDepth(pRoot->left, deep + 1), TreeDepth(pRoot->right, deep + 1));
}

int main() {
    TreeNode a = TreeNode(1);
    TreeNode b = TreeNode(2);
    TreeNode c = TreeNode(3);
    TreeNode d = TreeNode(4);
    TreeNode e = TreeNode(5);
    TreeNode f = TreeNode(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.right = &e;
    c.left = &f;
    cout << TreeDepth(&a,0) << endl;
    return 0;
}