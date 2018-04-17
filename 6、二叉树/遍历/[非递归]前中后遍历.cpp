#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
/*
先序遍历非递归：
1、借助栈，先将根入栈
2、弹出栈顶并打印，然后将其右孩子入栈（若有的话）
3、然后左孩子入栈 （若有的话）
4、然后回到2
*/
void preOrder(TreeNode *root) {
    stack<TreeNode> result;
    result.push(*root);
    while (result.size()) {
        TreeNode temp = result.top();
        cout << temp.val;
        result.pop();
        if (temp.right) result.push(*temp.right);
        if (temp.left) result.push(*temp.left);
    }
}
/*
中序遍历非递归：
1、借助栈，将整个树的左边界依次入栈(root=root->left)
2、若root为空，则弹出栈顶node并打印，另root=node.right，然后重复1
3、直到栈为空或root为空，结束
*/

void inOrder(TreeNode *root) {
    if (root) {
        stack<TreeNode> result;
        while (!result.empty() || root) {
            if (root) {//左边走到头
                result.push(*root);
                root = root->left;
            }
            else {
                cout << result.top().val;
                root = result.top().right;
                result.pop();
            }
        }

    }
}
/*
后序遍历（借助两个栈）***：
1、栈s1，初始值为根
2、弹出s1栈顶（root）放入栈s2，并将root左、右孩子依次*入栈s1（如果有的话）
3、直到s1为空
4、依次弹出s2的元素即为后序遍历结果
*/

void postOrder2(TreeNode *root) {
    stack<TreeNode> st1,st2;
    st1.push(*root);
    while (!st1.empty()) {
        TreeNode temp = st1.top();
        st2.push(temp);
        st1.pop();
        if (temp.left)st1.push(*temp.left);
        if (temp.right)st1.push(*temp.right);
    }
    while (!st2.empty()) {
        cout << st2.top().val;
        st2.pop();
    }
}
/*
后序遍历（借助一个栈）：
1、栈s1,变量root代表最近一次弹出并打印的阶段，变量c代表栈顶节点
2、初始root为根，c=NULL
3、若c的左孩子不为NULL，且root不等于c的左孩子也不等于c的右孩子，将c压入栈中
（因为root代表最近一次弹出并打印的节点，如果root为c的左或右孩子，说明c的右子树打印完毕，
就不需要将c的左孩子要入栈中了，否则说明左子树没有处理过，将左孩子压入栈中）
4、若3不满足，并且c的右孩子不为NULL，且root不等于c的右孩子，则将c的右孩子压入栈
（因为如果root为c的右孩子，代表右子树处理完毕，不需要将右孩子压入栈，否则就压入右孩子）
5、如果3、4都不满足，则将栈中弹出c并打印，然后令root=c
（说明左右子树都处理完毕，弹出栈顶并打印）
*/
void postOrder1(TreeNode *root) {
    if (root) {
        stack<TreeNode> st;
        st.push(*root);
        TreeNode c = NULL;
        while (!st.empty()) {
            c = st.top();
            if (c.left && root->val != c.left->val && root->val != c.right->val)
                st.push(*c.left);
            else if (c.right != NULL && root->val != c.right->val)
                st.push(*c.right);
            else {
                cout << st.top().val;
                st.pop();
                root = &TreeNode(c.val);
            }
        }
    }

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
    postOrder2(a);
    cout << endl;
    postOrder1(a);
}