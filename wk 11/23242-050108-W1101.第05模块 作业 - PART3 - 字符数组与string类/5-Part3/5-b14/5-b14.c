/* 2351050 ���� ��05 */
/* 2351719 ������ 2351757 ���ǲ� 2353269 ��һ 2350989 ������ 2351872 ������ */

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

    //��ȡ��������
    for (int i = 0; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++)
            scanf(" %c", &bomb[i][j]);

    //����׵������ͷ��׸�����Χ������
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (bomb[i][j] == '*') {
                count++;
                //ɨ��
                scan(bomb, i, j);
            }
        }
    }

    // ����׵�����
    if (count != 50) {
        printf("����1\n");
        return 0;
    }
    // �����׸�����Χ�������Ƿ�Ϸ�
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (bomb[i][j] != '0' && bomb[i][j] != '*') {
                printf("����2\n");
                return 0;
            }
        }
    }

    printf("��ȷ\n");

    return 0;
}