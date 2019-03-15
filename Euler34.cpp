/*************************************************************************
	> File Name: Euler34.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月13日 星期三 11时22分40秒
 ************************************************************************/
//各位数字的阶乘
#include <stdio.h>
#include <inttypes.h>

#define MAX_N 2540160 // 9! * 7

void init(int *num) {//递归计算阶乘
    num[0] = 1;
    for (int i = 1; i <= 10; i++) {
        num[i] = num[i - 1] * i;
    }
    return ;
}

bool is_valid(int n, int *a) {//分离位值
    if (n <= 2) return false;
    int sum = 0, x = n;
    while (n) {
        sum += a[n % 10];
        n /= 10;
    }
    return sum == x;
}

int solve(int *num) {//判断求和
    int sum = 0;
    for (int i = 10; i <= MAX_N; i++) {
        if (is_valid(i, num))
        sum += i;
    }
    return sum;
}

int main() {//函数调用
    int num[10] = {0};
    init(num);
    int sum = solve(num);
    printf("%d\n", sum);
    return 0;
}

