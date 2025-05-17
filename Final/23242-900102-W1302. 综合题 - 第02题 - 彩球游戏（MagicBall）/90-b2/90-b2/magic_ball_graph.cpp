/* 2351050 杨瑞晨 信05 */

#include "magic_ball.h"

void draw_border(int row, int col, bool divide, int sleep_time)
{
    cct_gotoxy(0, 1);
    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	if (divide) {
        // 顶边框
        cout << "╔";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "═╦";
            delay(sleep_time);
        }
        cout << "═╗" << endl;
        delay(sleep_time);
        // 中间的行
        for (int i = 0; i < row - 1; i++) {
            cout << "║";
            delay(sleep_time);
            for (int j = 0; j < col - 1; j++) {
                cout << "  ║";
                delay(sleep_time);
            }
            cout << "  ║" << endl;
            delay(sleep_time);
            // 行间分隔符
            cout << "╠";
            delay(sleep_time);
            for (int j = 0; j < col - 1; j++) {
                cout << "═╬";
                delay(sleep_time);
            }
            cout << "═╣" << endl;
            delay(sleep_time);
        }
        // 最后一行
        cout << "║";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "  ║";
            delay(sleep_time);
        }
        cout << "  ║" << endl;
        delay(sleep_time);
        // 底边框
        cout << "╚";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "═╩";
            delay(sleep_time);
        }
        cout << "═╝" << endl;
        delay(sleep_time);
    }
	else {
        // 顶边框
        cout << "╔";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "═";
            delay(sleep_time);
        }
        cout << "═╗" << endl;
        delay(sleep_time);
        // 中间的行
        for (int i = 0; i < row - 1; i++) {
            cout << "║ ";
            delay(sleep_time);
            for (int j = 0; j < col - 1; j++) {
                cout << "  ";
            }
            cout << " ║" << endl;
            delay(sleep_time);
            /* 行间分隔符
            cout << "╠";
            for (int j = 0; j < col - 1; j++) {
                cout << "═╬";
            }
            cout << "═╣" << endl;*/
        }
        // 最后一行
        cout << "║ ";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "  ";
        }
        cout << " ║" << endl;
        delay(sleep_time);
        // 底边框
        cout << "╚";
        delay(sleep_time);
        for (int j = 0; j < col - 1; j++) {
            cout << "═";
            delay(sleep_time);
        }
        cout << "═╝" << endl;
        delay(sleep_time);
	}
    cct_setcolor();
}

void draw_ball(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX], int sleep_time)
{
    //○◎●◊
    cct_gotoxy(0, 1);
    const int X = 2;
    const int Y = 2;
    const char* str1 = "●";
    const char* str2 = "◎";
    const char* str3 = "○";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int ballX = X + j * (divide + 1) * 2;
            int ballY = Y + i * (divide + 1);
            if (*(clear[i] + j) == 1) {
                cct_showstr(ballX, ballY, str1, *(ball[i] + j), COLOR_BLACK, 1);
            }
            else if (*(hint[i] + j) == 1) {
                cct_showstr(ballX, ballY, str2, *(ball[i] + j), COLOR_BLACK, 1);
            }
            else {
                cct_showstr(ballX, ballY, str3, *(ball[i] + j), COLOR_BLACK, 1);
            }
            delay(sleep_time);
        }
    }
    cct_setcolor();
}

void draw_clear(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
    //○◎●◊
    cct_gotoxy(0, 1);
    const int X = 2;
    const int Y = 2;
    const char* str1 = "○";
    const char* str2 = "¤";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int ballX = X + j * (divide + 1) * 2;
            int ballY = Y + i * (divide + 1);
            if (*(clear[i] + j) == 1) {
                for (int k = 0; k < 5; k++) {
                    cct_showstr(ballX, ballY, str2, *(ball[i] + j), COLOR_BLACK, 1);
                    Sleep(20);
                    cct_showstr(ballX, ballY, str1, *(ball[i] + j), COLOR_BLACK, 1);
                    Sleep(50);
                }
                cct_showstr(ballX, ballY, "  ", COLOR_HWHITE, COLOR_HWHITE, 1);
                Sleep(20);
            }
        }
    }
    cct_setcolor();
}

void draw_drop(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
    cct_gotoxy(0, 1);
    const int X = 2;
    const int Y = 2;
    const char* str = "○";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (clear[i][j] == 1) {
                ball[i][j] = 0;
            }
        }
    }
    // 掉落补位
    for (int j = 0; j < col; j++) {

        /*
        int write_row = row - 1;//写入位置初始为最后一行
        for (int i = row - 1; i >= 0; i--) {
            int ballX = X + j * (divide + 1) * 2;
            int ballY = Y + i * (divide + 1);
            if (ball[i][j] != 0) {
                ball[write_row][j] = ball[i][j];//值交换
                clear[write_row][j] = 0;//状态置0
                if (write_row != i) {
                    cct_showstr(ballX, ballY, "  ", COLOR_HWHITE, COLOR_HWHITE, 1);
                    Sleep(10);
                    cct_showstr(ballX, Y + write_row * (divide + 1), str, *(ball[i] + j), COLOR_BLACK, 1);
                    Sleep(60);

                    ball[i][j] = 0;//发现0，0上移
                    clear[i][j] = 1;//状态置1
                }
                write_row--;//写入位置上移
            }
        }
        */

        for (int i = row - 1; i >= 0; i--) {
            int ballX = X + j * (divide + 1) * 2;
            int ballY = Y + i * (divide + 1);
            if (ball[i][j] == 0 && ball[i - 1][j] != 0) {
                int k = i;
                while (ball[k][j] == 0 && k <= row - 1) {
                    ball[k][j] = ball[k - 1][j];
                    ball[k - 1][j] = 0;
                    clear[k][j] = 0;
                    clear[k - 1][j] = 1;
                    cct_showstr(ballX, Y + (k - 1) * (divide + 1), "  ", COLOR_HWHITE, COLOR_HWHITE, 1);
                    Sleep(30);
                    cct_showstr(ballX, Y + k * (divide + 1), str, *(ball[k] + j), COLOR_BLACK, 1);
                    Sleep(30);
                    k++;
                }
            }
        }
    }
    cct_setcolor();
}

void draw_fill(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
    cct_gotoxy(0, 1);
    const int X = 2;
    const int Y = 2;
    const char* str = "○";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int ballX = X + j * (divide + 1) * 2;
            int ballY = Y + i * (divide + 1);
            if (*(clear[i] + j) == 1) {
                cct_showstr(ballX, ballY, str, *(ball[i] + j), COLOR_BLACK, 1);
                Sleep(50);
            }
        }
    }
    cct_setcolor();
}