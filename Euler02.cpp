/*************************************************************************
	> File Name: Euler02-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 10时48分03秒
 ************************************************************************/
//循环数组 
#include<stdio.h>

int main() {
    int f[3] = {1, 0, 0}, sum = 0, n = 1;
    while (f[(n + 1) % 3] + f[(n + 2) % 3] <= 4000000) {//这里的条件为甚么不用f[n % 3] 
       // printf("%d\n", f[n % 3]);
        f[n % 3] = f[(n + 2) % 3] + f[(n + 1) % 3];
        if (!(f[n % 3] & 1))  sum += f[n % 3];
        n += 1;
                             
    }
    printf("%d\n", sum);
    return 0;
}

