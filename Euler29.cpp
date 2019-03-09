/*************************************************************************
	> File Name: Euler29.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 22时49分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define MAX_N 100

typedef struct {
    int32_t num, times;
} intnode;

typedef struct {
    int32_t p_num;
    intnode p[10];
} bigint;

int32_t prime[MAX_N + 5] = {0};
int32_t num_len;
bigint num[MAX_N * MAX_N];

void init() {
    for (int32_t i = 2; i <= MAX_N; i++)
        if (!prime[i])
            for (int32_t j = i; j <= MAX_N; j += i)
                if (!prime[j]) prime[j] = i;
    num_len = 0;
    memset(num, 0, sizeof(num));
}

void addBigInt(int32_t a, int32_t b) {
    int32_t times, pre_num, ind;
    while (a != 1) {
        pre_num = prime[a];
        times = 0;
        while (prime[a] == pre_num) {
            times++;
            a /= prime[a];
        }
        ind = num[num_len].p_num;
        num[num_len].p[ind].num = pre_num;
        num[num_len].p[ind].times = times * b;
        num[num_len].p_num++;
    }
    num_len++;
}

int32_t cmp(const void *a, const void *b) {
    return memcmp(a, b, sizeof(bigint));
}

int32_t main() {
    init();
    for (int32_t i = 2; i <= MAX_N; i++) {
        for (int32_t j = 2; j <= MAX_N; j++) {
            addBigInt(i, j);
        }
    }
    qsort(num, num_len, sizeof(bigint), cmp);
    int32_t total = 1;
    for (int32_t i = 1; i < num_len; i++) {
        if (memcmp(&num[i], &num[i - 1], sizeof(bigint)) == 0) continue;
        total++;
    }
    printf("%d\n", total);
    return 0;
}
