/*************************************************************************
	> File Name: Euler30.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 22时51分01秒
 ************************************************************************/
//上界估算
#include <stdio.h>
#include <math.h>
#define MAX_N 354294

int is_valid(int x) {
    int sum = 0,temp = x;
    while (x) {
        sum += (int)pow(x % 10, 5);//让个位5次方 并变成 整型
        x /= 10;//每次除以10 求出每一位数值
    }
    return temp == sum;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_valid(i)) continue;//判断条件是否成立
        printf("%d\n", i);
        sum += i;
    }
    printf("%d\n", sum);
    return 0;

}
