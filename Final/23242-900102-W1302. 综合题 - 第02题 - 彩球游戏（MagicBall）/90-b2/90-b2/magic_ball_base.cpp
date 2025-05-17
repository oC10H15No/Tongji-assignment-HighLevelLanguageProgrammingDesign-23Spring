/* 2351050 杨瑞晨 信05 */

#include "magic_ball.h"

void initial(int row, int col, int(*ball)[NUM_MAX], char select)//初始化数栈
{
	srand((unsigned int)time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(ball[i] + j) = rand() % 9 + 1;
		}
	}
}

void print_stack(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX])//打印数栈
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
			//可消除项填色
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
	// 清除 clear 数组
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			clear[i][j] = 0;
		}
	}
	// 检查行
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 2; ) {
			if (ball[i][j] == ball[i][j + 1] && ball[i][j] == ball[i][j + 2]) {
				int k = j;
				while (k < col && ball[i][k] == ball[i][j]) {
					clear[i][k] = 1;
					*score = *score + 1;
					k++;
				}
				j = k;  // 跳过已检查过的部分
			}
			else {
				j++;
			}
		}
	}
	// 检查列
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row - 2; ) {
			if (ball[i][j] == ball[i + 1][j] && ball[i][j] == ball[i + 2][j]) {
				int k = i;
				while (k < row && ball[k][j] == ball[i][j]) {
					clear[k][j] = 1;
					*score = *score + 1;
					k++;
				}
				i = k;  // 跳过已检查过的部分
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
	// 掉落补位
	for (int j = 0; j < col; j++) {
		int write_row = row - 1;//写入位置初始为最后一行
		for (int i = row - 1; i >= 0; i--) {
			if (ball[i][j] != 0) {
				ball[write_row][j] = ball[i][j];//值交换
				clear[write_row][j] = 0;//状态置0
				if (write_row != i) {
					ball[i][j] = 0;//发现0，0上移
					clear[i][j] = 1;//状态置1
				}
				write_row--;//写入位置上移
			}
		}
	}
}

void fill_numbers(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX])
{
	// 填充0和重新生成随机数
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (ball[i][j] == 0) {
				ball[i][j] = rand() % 9 + 1; // 生成1到9之间的随机数
			}
		}
	}
}

void find_hint(int row, int col, int (*ball)[NUM_MAX], int (*hint)[NUM_MAX]) 
{
	// 清除 hint 数组
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			hint[i][j] = 0;
		}
	}
	// 遍历每个元素，检查其与右边和下边相邻元素的交换是否能形成匹配
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