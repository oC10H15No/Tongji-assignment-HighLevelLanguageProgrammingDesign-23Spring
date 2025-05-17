/* 2351050 ���� ��05 */

#include "magic_ball.h"

void initial(int row, int col, int(*ball)[NUM_MAX], char select)//��ʼ����ջ
{
	srand((unsigned int)time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(ball[i] + j) = rand() % 9 + 1;
		}
	}
}

void print_stack(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX])//��ӡ��ջ
{
	cout << endl;
	cout << "  | ";
	for (int i = 0; i < col; i++) {
		cout << " " << i + 1 << " ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 0; i < col; i++) {
		cout << "---";
	}
	cout << endl;
	for (int i = 0; i < row; i++) {
		cout << char('A' + i) << " | ";
		for (int j = 0; j < col; j++) {
			cout << " ";
			int X, Y;
			cct_getxy(X, Y);
			//����������ɫ
			if (*(clear[i] + j) == 1) {
				const int bg_color = COLOR_HYELLOW;
				const int fg_color = COLOR_HBLUE;
				cct_showch(X, Y, '0' + *(ball[i] + j), bg_color, fg_color, 1);
			}
			else if (*(hint[i] + j) == 1) {
				const int bg_color = COLOR_HPINK;
				const int fg_color = COLOR_YELLOW;
				cct_showch(X, Y, '0' + *(ball[i] + j), bg_color, fg_color, 1);
			}
			else 
				cout << *(ball[i] + j);
			cct_setcolor();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void find_clear(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int *score)
{
	// ��� clear ����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			clear[i][j] = 0;
		}
	}
	// �����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 2; ) {
			if (ball[i][j] == ball[i][j + 1] && ball[i][j] == ball[i][j + 2]) {
				int k = j;
				while (k < col && ball[i][k] == ball[i][j]) {
					clear[i][k] = 1;
					*score = *score + 1;
					k++;
				}
				j = k;  // �����Ѽ����Ĳ���
			}
			else {
				j++;
			}
		}
	}
	// �����
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row - 2; ) {
			if (ball[i][j] == ball[i + 1][j] && ball[i][j] == ball[i + 2][j]) {
				int k = i;
				while (k < row && ball[k][j] == ball[i][j]) {
					clear[k][j] = 1;
					*score = *score + 1;
					k++;
				}
				i = k;  // �����Ѽ����Ĳ���
			}
			else {
				i++;
			}
		}
	}
}

void drop(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (clear[i][j] == 1) {
				ball[i][j] = 0;
			}
		}
	}
	// ���䲹λ
	for (int j = 0; j < col; j++) {
		int write_row = row - 1;//д��λ�ó�ʼΪ���һ��
		for (int i = row - 1; i >= 0; i--) {
			if (ball[i][j] != 0) {
				ball[write_row][j] = ball[i][j];//ֵ����
				clear[write_row][j] = 0;//״̬��0
				if (write_row != i) {
					ball[i][j] = 0;//����0��0����
					clear[i][j] = 1;//״̬��1
				}
				write_row--;//д��λ������
			}
		}
	}
}

void fill_numbers(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
	// ���0���������������
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (ball[i][j] == 0) {
				ball[i][j] = rand() % 9 + 1; // ����1��9֮��������
			}
		}
	}
}

void find_hint(int row, int col, int (*ball)[NUM_MAX], int (*hint)[NUM_MAX]) 
{
	// ��� hint ����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			hint[i][j] = 0;
		}
	}
	// ����ÿ��Ԫ�أ���������ұߺ��±�����Ԫ�صĽ����Ƿ����γ�ƥ��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j + 1 < col && match(row, col, ball, i, j, i, j + 1)) {
				hint[i][j] = 1;
				hint[i][j + 1] = 1;
			}
			if (i + 1 < row && match(row, col, ball, i, j, i + 1, j)) {
				hint[i][j] = 1;
				hint[i + 1][j] = 1;
			}
			/*if (j - 1 < col && match(row, col, ball, i, j, i, j - 1)) {
				hint[i][j] = 1;
				hint[i][j - 1] = 1;
			}
			if (i - 1 < row && match(row, col, ball, i, j, i - 1, j)) {
				hint[i][j] = 1;
				hint[i - 1][j] = 1;
			}*/
		}
	}
}