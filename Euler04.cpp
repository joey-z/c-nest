/*************************************************************************
	> File Name: Euler04.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时22分37秒
 ************************************************************************/

#include<stdio.h>
#define MAX_M 10000

int is_Palindrome(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
       // printf("%d\n", num);
    }

    return temp == num;
}
int main() {
    int ans = 1;
    for(int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (!is_Palindrome(i * j)) continue;
            if (i * j < ans) continue;
            ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}

