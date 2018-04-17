#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        if (n <= 0) {
            return vector<int>();
        }
        vector<int> res;  // 数组元素在树中父亲节点的编号
        stack<int> s;     // 栈 以递减方式存放元素值的位置index

        for (int i = 0; i < n; ++i) {
            int pos = -1; // 根编号为-1

                          // 当前访问的元素比栈顶大 栈中元素需要出栈
            while (!s.empty() && A[i] > A[s.top()]) {
                int tmp = s.top(); 
                s.pop();
                if (res[tmp] == -1 || A[i] < A[res[tmp]]) {
                    res[tmp] = i;
                }
            }
            // 找到了最近的比A[i]大的数
            if (!s.empty()) {
                pos = s.top();
            }

            s.push(i);
            res.push_back(pos);
        }

        return res;
    }
};

class MaxTree2 {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
        vector<int> answer;
        int i, j, k;
        for (i = 0; i < n; i++) {
            int left=A[i], right=A[i];
            for (j = i; j >= 0; j--) {
                if (A[j] > A[i]) {//找到第一个就行了
                    left = A[j];
                    break;
                }
            }
            for (k = i; k < n; k++) {
                if (A[k] > A[i]) {
                    right = A[k];
                    break;
                }
            }
            if (left == A[i] && right == A[i]) answer.push_back(-1);
            else if (left > right && right != A[i]) answer.push_back(k);
            else if (left < right && left != A[i]) answer.push_back(j);
            else if (left == A[i] && right != A[i]) answer.push_back(k);
            else if (left != A[i] && right == A[i]) answer.push_back(j);
        }
        return answer;
    }
};
int main() {
    vector<int> data = { 3,1,4,2 },answer;
    MaxTree test;
    answer = test.buildMaxTree(data, 4);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    return 0;
}