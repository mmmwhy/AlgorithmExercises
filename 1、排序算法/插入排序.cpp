#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertsort(vector<int> &A) {
    int len = A.size();
    for (int i = 1; i < len; i++) {
        for (int j = i; j >= 1; j--) {
            if (A[j - 1] > A[j]) swap(A[j - 1], A[j]);
        }
    }
}

int main() {
    vector<int> A = { 10,9,11,7,1,2,3,6,5,8,4 };
    insertsort(A);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    return 0;
}