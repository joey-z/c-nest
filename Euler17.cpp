/*************************************************************************
	> File Name: Euler17.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月21日 星期四 15时04分54秒
 ************************************************************************/

//统计字母个数
#include <stdio.h>
//num1用来保存1-19的字母个数 num2用来保存20～90的字母个数
int num1[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int num2[11] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int get_length(int num) {
    if (num < 20) {
        return num1[num];
    } else if (num < 100) {
        return num2[num / 10] + num1[num % 10];
    } else if (num < 1000) {
        //如果num>100时，要分是否为整百讨论（整百时没有and连接）
        //非整百时，用and连接除去一百的位
        if (num % 100 == 0) {
            return num1[num / 100] + 7;
        } else {
            return num1[num / 100] + 7 + 3 + get_length(num % 100); 
            //其中7为单词hundred 3为单词and
        }
    } else {
        return (3 + 8);
    }
}
int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += get_length(i);
    }
    printf("%d\n", sum);
    return 0;
}
