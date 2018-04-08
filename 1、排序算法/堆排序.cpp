#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void adjustTree(vector<int> &input, int i, int length) {//i调整的对象，length树的长度
    int child = i * 2 + 1;//左孩子
                          //右孩子比左孩子大？那先把左孩子提上去
    if (child < length) {
        if (child + 1 != length&&input[child] < input[child + 1]) child++;
        if (input[child] > input[i]) {
            swap(input[child], input[i]);
            adjustTree(input, child, length);
        }
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> result;
    if (input.empty() || k <= 0 || k > input.size()) return result;
    for (int i = k / 2 - 1; i >= 0; i--)
        adjustTree(input, i, k);
    int i = k;
    while (i < input.size()) {
        if (input[i] < input[0]) {
            swap(input[i], input[0]);
            adjustTree(input, 0, k);
        }
        else
            i++;
    }
    for (int i = 0; i < k; i++) {
        result.push_back(input[i]);
    }
    return result;
}

int main() {
    vector<int> n = { 4,5,1,6,2,7,3,8 };
    vector<int> answer = GetLeastNumbers_Solution(n,4);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}