//题目：https://www.nowcoder.com/practice/5b80ab166efa4551844657603227caeb
//思路：
//1、对比x和y大小，相等退出
//2、大的除2，循环1
#include<stdio.h>
int main(){
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF){
        while (x != y){
            if (x < y) y /= 2;
            else x /= 2;
        }
        printf("%d\n", x);
    }
    return 0;
}