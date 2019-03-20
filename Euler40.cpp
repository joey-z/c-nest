/*************************************************************************
	> File Name: Euler40.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 11时14分02秒
 ************************************************************************/

//钱珀瑙恩常数
#include <stdio.h>
#include <inttypes.h>
 
int32_t GetDi(int32_t n) {
    if (n <= 9) return n;
    n -= 10;
    int32_t cur = 10, j = 2, num;
    while (n >= j * (cur * 10 - cur)) {
        n -= j * (cur * 10 - cur);
        cur *= 10; j += 1;
    }
    num = n / j + cur;
    for (int32_t i = 0; i < j - n % j - 1; i++) num /= 10;
    return num % 10;
}
 
int32_t main() {
    int32_t p = 1, h = 1;
    for (int32_t i = 0; i < 7; i++) {
        p *= GetDi(h);
        h *= 10;
    }
    printf("%d\n", p);
    return 0;
}

