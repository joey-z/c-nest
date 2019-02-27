/*************************************************************************
	> File Name: Euler25.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月21日 星期四 15时06分05秒
 ************************************************************************/

//斐波那契数列和大整数加法
#include <stdio.h>
#define MAX 1000
int fib[3][MAX + 5] = {{0, 0}, {1, 1}, {1, 1}};
int main() {
    int n = 2;
    do {
        n += 1;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            a[i] = b[i] + c[i];
        }
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    } while (fib[n % 3][0] < 1000);
    printf("%d\n", n);
    return 0;
}
