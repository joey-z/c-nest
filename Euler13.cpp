/*************************************************************************
	> File Name: Euler13.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月21日 星期四 15时05分24秒
 ************************************************************************/

//大整数加法
#include <stdio.h>
#include <string.h>
#define MAX 5000
int sum[MAX + 5] = {1, 0};
int main() {
    char temp[55];
    for (int i = 0; i < 100; i++) {
        scanf("%s", temp);
        int len = strlen(temp);
        if(sum[0] < len) sum[0] = len; //如果和的长度小于50
        for (int j = 0; j < len; j++) {
            sum[len - j] += temp[j] - '0';
        }
        for (int j = 1; j <= sum[0]; j++) {
            if (sum[j] < 10) continue;
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
            sum[0] += (j == sum[0]);
        }    
    }
    for (int i = sum[0]; i > sum[0] - 10; i--) {
        printf("%d", sum[i]);
    }
    printf("\n");
    return 0;
}
