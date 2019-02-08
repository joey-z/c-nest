/*************************************************************************
	> File Name: Euler18.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年01月31日 星期四 18时49分28秒
 ************************************************************************/

//最大路径
#include <stdio.h>
#include <inttypes.h>

int32_t f[22][22] = {0};//代表从当前位置走到最后所获得得最大值
int32_t num[22][22] = {0};

int32_t main() {
    for (int32_t i = 0; i < 20; ++i) {
        for (int32_t j = 0; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int32_t i = 0; i < 20; ++i) {
        f[19][i] = num[19][i];
    }
    for (int32_t i = 18; i >= 0; --i) {
        for (int32_t j = 0; j <= i; ++j) {
            f[i][j] = f[i + 1][j];
            if (f[i + 1][j + 1] > f[i][j])
                f[i][j] = f[i + 1][j + 1];
            f[i][j] += num[i][j];
        }
    }
    printf("%d\n", f[0][0]);
    return 0;
}
