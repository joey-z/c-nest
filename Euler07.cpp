/*************************************************************************
	> File Name: Euler07.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月20日 星期一 19时45分14秒
 ************************************************************************/
 //素数筛 
#include<stdio.h>
#define MAX_N 1000000

int is_prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i< MAX_N; i++) {
        if (is_prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            is_prime[j] = 1;
                    
        }
            
    }
    for (int i = 2; i < MAX_N; i++) {
        if (is_prime[i]) continue;
        is_prime[++is_prime[0]] = i;
            
    }

}
int main() {
    init();
    printf("%d\n", is_prime[10001]);

    return 0;

}

