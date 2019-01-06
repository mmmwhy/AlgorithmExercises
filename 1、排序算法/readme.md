---
title: 算法导论 第7章 快速排序
date: 2017-03-09 22:22:16
tags: [sort,Algorithms,Python,cpp]
categories: Algorithms
---
> 快速排序是一种非常优秀的排序方法 

<!--more-->
对于包含n个数的输入数组来说，快速排序是一种最坏情况是
$$\theta(n^{2})$$ 的算法，虽然表现出的状态和堆排序是相似的。但实际上，快速排序的复杂度绝大部分情况的都可以做到
$$\theta(nlgn)$$)


---

# 快排算法的描述

## 快排算法分为两部分：
- 分解：数组`A[p..r]`被分解为`A[p...q-1]`和`A[q+1...r]`，其中`A[p...q-1]`内的元素都比`A[q]`小，`A[q+1...r]`中的元素都比`A[q]`大。
- 解决：通过调用快速排序，解决`A[p...q-1]`和`A[q+1...r]`。
- 合并：因为元素都是原址排序，因此不需要合并操作。

## 伪代码
对整个数组进行递归排序：
``` cpp
QUICKSORT(A,p,r)
if p < r:
    q = PARTITION(A,p,r);
    QUICKSORT(A,p,q-1);
    QUICKSORT(A,q+1,r); 
```
快速排序算法的关键是PARTITION过程，它对A[p..r]进行就地重排：
``` cpp
PARTITION(A,p,r)
x = A[r]
i = p-1
for j = p to r-1// A[r]是待比较的元素
  if A[j] ≤ r// 若A[j]比主元小
    i = i + 1 // i往后一位（符合，不用替换；不符合i就停在这个地方，等着j过来叫唤）
    exchange A[i] with A[j]//倘若A[j]比主元小，其实是不发生交换的。
exchange A[i+1] with A[r]
return i + 1
```
借用一张《算法导论》的图
![Introduction to Algorithms](http://cdn.lifeiyang.cn/blog/20170309/191837286.png)

# 参考代码

## C++代码
基本和伪代码是一样的
``` cpp
#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print(int *A, int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}

int PARTITION(int *A, int p, int r) {
    int i = p - 1;
    int x = A[r];
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}


void QUICKSORT(int A[], int p, int r) {
    if (p < r) {
        int q = PARTITION(A, p, r);
        QUICKSORT(A, p, q - 1);
        QUICKSORT(A, q + 1, r);
    }
    return;
}


int main() {
    int A[] = { 9,10,11,7,1,2,3,6,5,8,4 };
    print(A, 11);
    QUICKSORT(A, 0, 10);
    print(A,11);
    return 0;
}
```
期间出了一个错误，error C3861: 找不到标识符。后发现是因为把PARTITION放在了QUICKSORT后边，导致QUICKSORT找不到PARTITION。

## python代码
``` python
# coding=utf-8
def PARTITION(A,p,r):
    x = A[r]
    i = p - 1
    for j in range(p,r):
        if A[j]<=x:
            i = i + 1
            temp = A[i]
            A[i] = A[j]
            A[j] = temp #python没有指针，这个地方稍微不一样
    temp = A[i+1]
    A[i+1] = A[r]
    A[r] = temp
    return i+1


def QUICKSORT(A,p,r):
    if p >= r:
        return
    q = PARTITION(A,p,r)
    QUICKSORT(A,p,q-1)
    QUICKSORT(A,q+1,r)
    
if __name__ == '__main__':
    l =  [9,10,11,7,1,2,3,6,5,8,4] ;
    QUICKSORT(l,0,len(l)-1)
    print(l)
```
这里使用的数组是list，声明方式是`    l =  [9,10,11,7,1,2,3,6,5,8,4] `，注意那个[]。如果使用元组tuple，会导致元素不能修改。
