/*************************************************************************
	> File Name:Euler05.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时23分42秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);

}
int main() {
    int ans = 1;
    for (int i = 11; i < 21; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}

