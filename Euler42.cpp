/*************************************************************************
	> File Name: Euler42.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年03月21日 星期四 08时33分33秒
 ************************************************************************/

//编码三角形数
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "Euler42.h"
 
bool isTriangleNumber(int32_t n) {//判断是否是三角形数
    int32_t m = (int32_t)floor(sqrt(n * 2));
    return m * (m + 1) / 2 == n;
}
 
int32_t main() {
    int32_t i = 0, sum = 0, total = 0;
    while (wordList[i].length() != 0) {
        sum = 0;
        for (int32_t j = 0; j < wordList[i].length(); j++) {
            sum += wordList[i][j] - 'A' + 1;
        }
        if (isTriangleNumber(sum)) ++total;
        ++i;
    }
    printf("%d\n", total);
    return 0;
}

