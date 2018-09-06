/*************************************************************************
	> File Name: ol06.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时22分48秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    int sum = 0, num = 5050;
    for (int i = 1; i < 101; i++) {
        sum += pow(i, 2);        
    }
    num *= num;
    printf("%d\n",num - sum);
    return 0;
}

