//从上往下打印二叉树
//题目：https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701
//思路：用队列，root入，然后root出，左右孩子入，循环。
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
}; 

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> answer;
        if (root == NULL) return answer;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            answer.push_back(root->val);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        return answer;
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
    Solution test;
    vector<int> answer =  test.PrintFromTopToBottom(a);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}