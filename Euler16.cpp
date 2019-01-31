/*************************************************************************
	> File Name: Euler16.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年01月31日 星期四 18时47分51秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000
#define BASE 10

int32_t ans[MAX_N + 5] = {0};

int32_t mul() {
    ans[0] = ans[1] = 1;
    for (int32_t i = 0; i < 100; i++) {
        for (int32_t j = 1; j <= ans[0]; j++) {
            ans[j] *= 1024;
        }
        for (int32_t j = 1; j <= ans[0]; j++) {
            if (ans[j] < MAX_N) continue;
            ans[j + 1] += ans[j] / MAX_N;
            ans[j] %= MAX_N;
            if (j == ans[0]) ans[0]++;
        }
    }
    return 0;
}

int main() {
    mul();
    int32_t sum = 0;
    for (int32_t i = 1; i <= ans[0]; i++) {
        while (ans[i]) {
            sum += ans[i] % BASE;
            ans[i] /= BASE;
        }
    }
    printf("%d\n", sum);
    return 0;
}
