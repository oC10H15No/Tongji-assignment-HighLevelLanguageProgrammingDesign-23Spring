/* 2351050 杨瑞晨 信05 */
/* 2351719 杨其沅 2351757 姜智博 2353269 李一 2350989 张启政 2351872 宋文轩 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_X 26
#define MAX_Y 10

void scan(char bomb[MAX_Y][MAX_X], int y, int x) {
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && i < MAX_Y && j >= 0 && j < MAX_X && bomb[i][j] != '*') {
                bomb[i][j]--;
            }
        }
    }
}

int main()
{
    char bomb[MAX_Y][MAX_X] = { 0 };
    int count = 0;

    //读取雷区数据
    for (int i = 0; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++)
            scanf(" %c", &bomb[i][j]);

    //检查雷的数量和非雷格子周围的数字
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (bomb[i][j] == '*') {
                count++;
                //扫雷
                scan(bomb, i, j);
            }
        }
    }

    // 检查雷的数量
    if (count != 50) {
        printf("错误1\n");
        return 0;
    }
    // 检查非雷格子周围的数字是否合法
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (bomb[i][j] != '0' && bomb[i][j] != '*') {
                printf("错误2\n");
                return 0;
            }
        }
    }

    printf("正确\n");

    return 0;
}