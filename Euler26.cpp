/*************************************************************************
	> File Name: Euler26.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月07日 星期四 22时03分58秒
 ************************************************************************/
//倒数循环节
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define MAX_N 1000

int32_t rest[MAX_N] = {0};//余数第一次出现的位置

int32_t GetLoopLength(int32_t n) {
    memset(rest, 0, sizeof(rest));//初始化
    int ret = 1 % n, ind = 1;//第一轮
    while (rest[ret] == 0 && ret) {
        rest[ret] = ind++;
        ret *= 10;
        ret %= n;
    }
    return ret ? ind - rest[ret] : 0;
}

int32_t main() {
    int32_t maxLen = 0, curLen, num;
    for (int32_t i = 1; i <= MAX_N; i++) {
        curLen = GetLoopLength(i);
        if (curLen > maxLen) {
            num = i;
            maxLen = curLen;
        }
    }
    printf("%d\n", num);
    return 0;
}
