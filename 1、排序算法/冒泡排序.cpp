#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void popsort(vector<int> &A) {
    int len = A.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i-1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> A = { 9,10,11,7,1,2,3,6,5,8,4 };
    popsort(A);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    return 0;
}