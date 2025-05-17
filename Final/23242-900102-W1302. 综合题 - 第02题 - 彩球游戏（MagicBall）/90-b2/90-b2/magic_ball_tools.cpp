/* 2351050 杨瑞晨 信05 */

#include "magic_ball.h"

void wait_for_enter()
{
	while (1) {
		char enter = _getch();
		if (enter == 13)
			return;
	}
}

bool is_all_zero(int row, int col, int arr[NUM_MAX][NUM_MAX]) 
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                return false; // 发现1，返回false
            }
        }
    }
    return true; // 遍历完未发现1，返回true
}

void end()
{
	int X, Y;
	cct_getxy(X, Y);
	while (1) {
		char t[4] = { 0 };
		cct_gotoxy(X, Y);
		cout << "本小题结束，请输入End继续:           ";
		cct_gotoxy(30, Y);
		cin.getline(t, 4);
		if ((t[0] == 'E' || t[0] == 'e') && (t[1] == 'N' || t[1] == 'n') && (t[2] == 'D' || t[2] == 'd')) {
			cin.clear();
			break;
		}
		else {
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入";
			cct_gotoxy(X, Y);
			cin.clear();
			continue;
		}
	}
}

bool match(int row, int col, int ball[NUM_MAX][NUM_MAX], int x1, int y1, int x2, int y2)
{
	// 交换两个位置的值
	int temp = ball[x1][y1];
	ball[x1][y1] = ball[x2][y2];
	ball[x2][y2] = temp;
	// 检查交换后是否能形成三个或更多相同颜色的球
	bool match = 0;
	// 检查行
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 2; j++) {
			if (ball[i][j] == ball[i][j + 1] && ball[i][j] == ball[i][j + 2]) {
				match = 1;
			}
		}
	}
	// 检查列
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row - 2; i++) {
			if (ball[i][j] == ball[i + 1][j] && ball[i][j] == ball[i + 2][j]) {
				match = 1;
			}
		}
	}
	// 交换回原来的值
	ball[x2][y2] = ball[x1][y1];
	ball[x1][y1] = temp;
	return match;
}

void delay(int sleep_time)
{
	if (sleep_time > 0)
		Sleep(sleep_time);
	else
		;
}

int read_mouse(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX], const int length, char select, int* x, int* y)
{
	int X = 0, Y = 0;
	int ret, maction;
	int loop = 1;
	int keycode1, keycode2;

	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	char colLabels[] = "ABCDEFGHI";
	while (1) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(0, length - 3);
			cout << "[当前光标] ";
			bool legal = 0;
			int boardY = (X - 1) / 4;
			int boardX = (Y - 2) / 2;
			if ((X - 1) % 4 == 0 || (X - 1) % 4 == 3 || (Y - 2) % 2 == 1) { // 边框处
				legal = 0;
			}
			else if (boardX >= 0 && boardX < row && boardY >= 0 && boardY < col) {
				legal = 1;
			}
			if (legal) {
				cout << setw(2) << colLabels[boardX] << "行" << setw(2) << boardY + 1 << "列              ";
			}
			else {
				cout << "位置非法";
			}
			
			if (legal) {
				//左键选择
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {
					cct_gotoxy(0, length - 3);
				
					if (hint[boardX][boardY] == 1) {
						*x = boardX;
						*y = boardY;
						
						cout << "当前选择" << colLabels[boardX] << "行" << boardY + 1 << "列       ";
						Sleep(300);
						cct_enable_mouse();
						break;
					}
					else {
						cout << "不能选择" << colLabels[boardX] << "行" << boardY + 1 << "列       ";
						Sleep(200);
						cct_enable_mouse();
						continue;
					}
				}
				//右键退出
				if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					return -1;
				}
			}
		} //end of if (CCT_MOUSE_EVENT)
	} //end of while(1)

	cct_disable_mouse();	//禁用鼠标
	return 0;
}

