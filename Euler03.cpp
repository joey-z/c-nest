/*************************************************************************
	> File Name: ol03.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时22分26秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 600851475143
#include <inttypes.h>

int main() {
    int64_t num = MAX_N, n = 2, ans = 0;
    while (n * n <= num) {
        if (num % n == 0) ans = n;
        while (num % n == 0) num /= n;
        n += 1;
    }
    if (num != 0) ans = num;

    printf("%"PRId64"\n",ans);

    return 0;
}

