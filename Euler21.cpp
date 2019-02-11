/*************************************************************************
	> File Name: Euler21.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月11日 星期一 18时44分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};//储存质数值
int pnum[MAX_N + 5] = {0};//存储最小素因子幂次值
int fnum[MAX_N + 5] = {0};//储存约数个数
int dnum[MAX_N + 5]  = {0};//储存约数和

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {//线性筛
            prime[++prime[0]] = i;
            pnum[i] = 1;
            fnum[i] = 2;
            dnum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[prime[j] * i] = 1;//非素数标记
            if (i % prime[j] == 0) {//约数公式
                pnum[prime[j] * i] = pnum[i] + 1;
                fnum[prime[j] * i] = fnum[i] / (pnum[i] + 1) * (pnum[i] + 2);
                dnum[prime[j] * i] = dnum[i] / (pow(prime[j], pnum[i] + 1) - 1) *
                (pow(prime[j], pnum[i] + 2) - 1);
                break;
            } else {
                pnum[prime[j] * i] = 1;//互素
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
    for (int i = 0; i <= MAX_N; i++) {
        dnum[i] -= i;//去本身
    }
    int sum = 0;
    for (int i = 0; i <= MAX_N; i++) {//求和
        if (dnum[i] <= MAX_N && dnum[i] != i && dnum[dnum[i]] == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
