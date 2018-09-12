/*************************************************************************
	> File Name: Euler10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时24分13秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000

int is_prime[MAX_N + 5] = {0};
int64_t ans = 0;

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
        is_prime[j] = 1;
        }
    }
    for (int i = 2; i  <= MAX_N; i++) {
        if (is_prime[i]) {
            continue;
        }
        ans += i;
        is_prime[++is_prime[0]] = i;
    }
}

int main() {
    
    init();
    printf("%"PRId64"\n", ans);


    return 0;
}

