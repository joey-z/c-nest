/*************************************************************************
	> File Name: Euler35.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月13日 星期三 10时23分13秒
 ************************************************************************/

//圆周素数
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define MAX_N 1000000

int32_t isPrime[MAX_N + 5] = {0};//标记素数
int32_t prime[MAX_N + 5] = {0};//存放素数

void initPrime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) prime[++prime[0]] = i;
        for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            isPrime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

bool isCircularPrime(int32_t n) {
    if (isPrime[n]) return false;
    int32_t x = n, h, j;
    h = (int32_t)pow(10, floor(log10(n)));//权值
    j = (int32_t)(floor(log10(n))) + 1;//位数
    for (int32_t i = 0; i < j; i++) {
        x = x /10 + (x % 10) * h;
        if (isPrime[x]) return false;
    }
    return true;
}

int32_t solve() {
    int32_t many = 0;
    for (int32_t i = 1; i <= prime[0]; i++) {
        if (prime[i] > MAX_N) break;
        if (isCircularPrime(prime[i])) many++;
    }
    return many;
}
int main() {
    initPrime();
    int32_t many = solve();
    printf("%d\n", many);
    return 0;
}
