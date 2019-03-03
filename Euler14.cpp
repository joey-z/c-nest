/*************************************************************************
	> File Name: Euler14.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月21日 星期四 15时03分34秒
 ************************************************************************/

//记忆化　注意记忆化数组访问越界，当保存的值超过下标时
#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
#define KEEP_RANGE 2000000

int keep_ans[KEEP_RANGE + 5] = {0};

int get_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x];  //x必须小于KEEP_RANGE,否则越界
    int temp_ans;
    if (x & 1) temp_ans = get_length(x * 3 + 1) + 1;
    else temp_ans = get_length(x >> 1) + 1;
    if (x <= KEEP_RANGE) keep_ans[x] = temp_ans;           //x小于KEEP_RANGE时才能保存
    return temp_ans;
}

int main() {
    int ans = 0, ans_length = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp_length = get_length(i);
        if (temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n", ans, ans_length);
    return 0;
}
