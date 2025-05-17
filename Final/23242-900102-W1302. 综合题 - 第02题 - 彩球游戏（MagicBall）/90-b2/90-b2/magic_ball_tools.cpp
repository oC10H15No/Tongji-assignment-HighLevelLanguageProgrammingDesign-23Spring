/* 2351050 ���� ��05 */

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
                return false; // ����1������false
            }
        }
    }
    return true; // ������δ����1������true
}

void end()
{
	int X, Y;
	cct_getxy(X, Y);
	while (1) {
		char t[4] = { 0 };
		cct_gotoxy(X, Y);
		cout << "��С�������������End����:           ";
		cct_gotoxy(30, Y);
		cin.getline(t, 4);
		if ((t[0] == 'E' || t[0] == 'e') && (t[1] == 'N' || t[1] == 'n') && (t[2] == 'D' || t[2] == 'd')) {
			cin.clear();
			break;
		}
		else {
			cct_gotoxy(0, Y + 1);
			cout << "�����������������";
			cct_gotoxy(X, Y);
			cin.clear();
			continue;
		}
	}
}

bool match(int row, int col, int ball[NUM_MAX][NUM_MAX], int x1, int y1, int x2, int y2)
{
	// ��������λ�õ�ֵ
	int temp = ball[x1][y1];
	ball[x1][y1] = ball[x2][y2];
	ball[x2][y2] = temp;
	// ��齻�����Ƿ����γ������������ͬ��ɫ����
	bool match = 0;
	// �����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 2; j++) {
			if (ball[i][j] == ball[i][j + 1] && ball[i][j] == ball[i][j + 2]) {
				match = 1;
			}
		}
	}
	// �����
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row - 2; i++) {
			if (ball[i][j] == ball[i + 1][j] && ball[i][j] == ball[i + 2][j]) {
				match = 1;
			}
		}
	}
	// ������ԭ����ֵ
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
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	char colLabels[] = "ABCDEFGHI";
	while (1) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(0, length - 3);
			cout << "[��ǰ���] ";
			bool legal = 0;
			int boardY = (X - 1) / 4;
			int boardX = (Y - 2) / 2;
			if ((X - 1) % 4 == 0 || (X - 1) % 4 == 3 || (Y - 2) % 2 == 1) { // �߿�
				legal = 0;
			}
			else if (boardX >= 0 && boardX < row && boardY >= 0 && boardY < col) {
				legal = 1;
			}
			if (legal) {
				cout << setw(2) << colLabels[boardX] << "��" << setw(2) << boardY + 1 << "��              ";
			}
			else {
				cout << "λ�÷Ƿ�";
			}
			
			if (legal) {
				//���ѡ��
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {
					cct_gotoxy(0, length - 3);
				
					if (hint[boardX][boardY] == 1) {
						*x = boardX;
						*y = boardY;
						
						cout << "��ǰѡ��" << colLabels[boardX] << "��" << boardY + 1 << "��       ";
						Sleep(300);
						cct_enable_mouse();
						break;
					}
					else {
						cout << "����ѡ��" << colLabels[boardX] << "��" << boardY + 1 << "��       ";
						Sleep(200);
						cct_enable_mouse();
						continue;
					}
				}
				//�Ҽ��˳�
				if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					return -1;
				}
			}
		} //end of if (CCT_MOUSE_EVENT)
	} //end of while(1)

	cct_disable_mouse();	//�������
	return 0;
}

