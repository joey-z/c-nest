/*************************************************************************
	> File Name: Euler11.cpp
	> Author: Zoe 
	> Mail: 
	> Created Time: 2019年02月21日 星期四 15时01分40秒
 ************************************************************************/
#include <stdio.h>
//方向数组　行数代表方向的个数，列数代表维度
int dir_arr[4][2] = {
    1, 1, 1, -1,
    0, 1, 1, 0
};
//四个方向两个维度（平面）的方向数组
int main(){
    int num[30][30] = {0};
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", num[i] + j);  
        }
    }
    //将数组初始化为0, 给其加上一个边框（从5行5列开始输入），即可不必判断越界条件。
    int ans = 0;
    for (int x = 5; x < 25; x++) {
        for (int y = 5; y < 25; y++) { 
            for (int k = 0; k < 4; k++) { //四个方向
                int p = 1;
                for (int step = 0; step < 4; step++) { //每个方向走4步
                    int xx = x + step * dir_arr[k][0];
                    int yy = y + step * dir_arr[k][1];
                    p *= num[xx][yy];
                }
                if(p > ans) ans = p;
            }
        }
    }  
    printf("%d\n", ans);
    return 0;
}
