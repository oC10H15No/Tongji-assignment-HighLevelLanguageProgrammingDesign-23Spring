/* 2351050 杨瑞晨 信05 */

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

#include "hanoi.h"

int topA = 0, topB = 0, topC = 0;
int stackA[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stackB[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stackC[10] = { 0,0,0,0,0,0,0,0,0,0 };
int countN = 0;
int sleepTime = 3;

void delay()//延迟时间
{
	switch (sleepTime) {
		case 0:
			while (1) {
				int enter = _getch();
				if (enter == 13)
					break;
			}
			break;
		case 1:
			Sleep(200);
			break;
		case 2:
			Sleep(100);
			break;
		case 3:
			Sleep(50);
			break;
		case 4:
			Sleep(10);
			break;
		case 5:
			break;
		default:
			break;
	}
}

void move(char src, char dst)//栈中数字移动
{
	int temp = 0;

	if (src == 'A') {
		temp = stackA[--topA];
		stackA[topA] = 0;
	}
	else if (src == 'B') {
		temp = stackB[--topB];
		stackB[topB] = 0;
	}
	else if (src == 'C') {
		temp = stackC[--topC];
		stackC[topC] = 0;
	}

	if (dst == 'A') {
		stackA[topA++] = temp;
	}
	else if (dst == 'B') {
		stackB[topB++] = temp;
	}
	else if (dst == 'C') {
		stackC[topC++] = temp;
	}
}

void printLevelStack()//打印水平内部数组
{
	int i;
	cout << " A:";
	for (i = 0; i < 10; i++) {
		if (stackA[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackA[i];
	}
	cout << " B:";
	for (i = 0; i < 10; i++) {
		if (stackB[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackB[i];
	}
	cout << " C:";
	for (i = 0; i < 10; i++) {
		if (stackC[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackC[i];
	}
}

void printVerticalStack(char select) //打印垂直内部数组
{
	const int X = 28;
	int Y;
	if (select == '8' || select == '9')
		Y = 28;
	else
		Y = 15;
	
	//塔底
	cct_gotoxy(X - 1, Y + 1);
	cout << setw(25) << setfill('=') << "=" << endl;
	cct_gotoxy(X + 1, Y + 2);
	cout << setfill(' ') << "A         B         C";

	//塔
	int i;
	for (i = 0; i < 10; i++) {
		cct_gotoxy(X, Y - i);
		if (stackA[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackA[i];
	}
	for (i = 0; i < 10; i++) {
		cct_gotoxy(X + 10, Y - i);
		if (stackB[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackB[i];
	}
	for (i = 0; i < 10; i++) {
		cct_gotoxy(X + 20, Y - i);
		if (stackC[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackC[i];
	}
}

void clearStack()//清空栈及计数器
{
	countN = 0;
	sleepTime = 3;
	for (int i = 0; i < 10; i++) {
		stackA[i] = 0;
		stackB[i] = 0;
		stackC[i] = 0;
	}
	topA = 0;
	topB = 0;
	topC = 0;
}

void printMove(int n, char src, char dst, char select) //打印移动
{
	const int X = 0;
	const int Y = 20;
	countN++;
	if (select == '1')
		cout << setw(2) << n << "# " << src << "---->" << dst << endl;
	else if (select == '2')
		cout << "第" << setiosflags(ios::right) << setw(4) << countN << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") " << endl;
	else if (select == '3') {
		cout << "第" << setiosflags(ios::right) << setw(4) << countN << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		cout << endl;
	}
	else if (select == '4') {
		delay();
		cct_gotoxy(X, Y);
		cout << "第" << setiosflags(ios::right) << setw(4) << countN << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		printVerticalStack(select);
	}
	else if (select == '6') {
		cout << "从 " << src << " 移动到 " << dst << " , 共 " << n << " 层" << endl;
	}
	else if (select == '7') {
		move(src, dst);
		plateMoveVertical(n, src, dst, UP);
		plateMoveLevel(n, src, dst);
		plateMoveVertical(n, src, dst, DOWN);
	}
	else if (select == '8') {
		cct_setcolor();
		delay();
		cct_gotoxy(0, 32);
		cout << "第" << setiosflags(ios::right) << setw(4) << countN << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		printVerticalStack(select);

		plateMoveVertical(n, src, dst, UP);
		plateMoveLevel(n, src, dst);
		plateMoveVertical(n, src, dst, DOWN);
	}
	else if (select == '9') {
		cct_setcolor();
		cct_gotoxy(0, 32);
		cout << "第" << setiosflags(ios::right) << setw(4) << countN << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		printVerticalStack(select);

		plateMoveVertical(n, src, dst, UP);
		plateMoveLevel(n, src, dst);
		plateMoveVertical(n, src, dst, DOWN);
	}
		
}

void initial(int n, char src)
{
	//初始化栈
	int i = n, j = 0;
	for (i = n; i > 0; i--) {
		if (src == 'A')
			stackA[j] = i;
		else if (src == 'B')
			stackB[j] = i;
		else if (src == 'C')
			stackC[j] = i;
		j++;
	}
	if (src == 'A')
		topA = j;
	else if (src == 'B')
		topB = j;
	else if (src == 'C')
		topC = j;
}

void hanoi(int n, char src, char tmp, char dst, char select)//1 2 3 4 7 8共用的递归函数
{
	if (n == 1) {
		printMove(n, src, dst, select);
	}
	else {
		hanoi(n - 1, src, dst, tmp, select);
		if (select == '7')//7 只有第一个盘移动
			return;
		printMove(n, src, dst, select);
		hanoi(n - 1, tmp, src, dst, select);
	}
}

void input(int *n, char *src, char *tmp, char *dst, char select) // 1 2 3 4 6 7 8 9 共用的输入函数 形参为指针型变量
{
	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> *n;
		if (cin.fail() || *n < 1 || *n > 10) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> *src;
		if (cin.fail() || *src < 'A' || *src > 'c' || (*src > 'C' && *src < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (*src > 96) {
				*src = *src - 32;//小写字母转大写
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> *dst;
		if (cin.fail() || *dst < 'A' || *dst > 'c' || (*dst > 'C' && *dst < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (*dst > 96) {
				*dst = *dst - 32;//小写字母转大写
			}
			if (*src == *dst) {
				cout << "目标柱(" << *src << ")" << "不能与起始柱(" << *dst << ")相同" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}

	if (select == '4' || select == '8') {
		while (1) {
			cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
			cin >> sleepTime;
			if (cin.fail() || sleepTime < 0 || sleepTime > 5) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}
		}
	}

	*tmp = 3 * 'B' - *src - *dst;
	
	initial(*n, *src);
}

void drawColumn()//画柱子
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	int LENGTH = 23;
	const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
	const int fg_color = COLOR_HYELLOW;

	for (int i = 0; i < 3; i++) { //画横向底座
		cct_showch(X + i * (LENGTH + 3), Y, ' ', bg_color, fg_color, LENGTH);
		Sleep(50);
		for (int j = 0; j < 12; j++) //画纵向轴
		{
			cct_showch(X + 11 + i * (LENGTH + 3), Y - j, ' ', bg_color, fg_color, 1);
			Sleep(50);
		}
	}
}

void drawPlate(int n, char src)//画初始盘子
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	int LENGTH = 23;
	for (int i = n; i > 0; i--) {
		Sleep(80);
		cct_showch(X + 11 - i + (src - 'A') * (LENGTH + 3), Y - 1 - n + i, ' ', i, i, i * 2 + 1);
	}
}

void plateMoveVertical(int n, char src, char dst, bool direction)//盘子垂直移动    direction: UP -- 1  DOWN -- 0
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	const int endY = 2;
	int LENGTH = 23;
	if (direction) {
		if (src == 'A') {
			for (int y = Y - 1 - topA; y > endY; y--) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);//擦除原有的盘子
				if (y > 4) {
					cct_showch(X + 11 + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, n, 1);//补齐亮黄色柱子
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y - 1, ' ', n, n, n * 2 + 1);//打印新的盘子
			}
		}
		if (src == 'B') {
			for (int y = Y - 1 - topB; y > endY; y--) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
				if (y > 4) {
					cct_showch(X + 11 + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, n, 1);
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y - 1, ' ', n, n, n * 2 + 1);
			}
		}
		if (src == 'C') {
			for (int y = Y - 1 - topC; y > endY; y--) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
				if (y > 4) {
					cct_showch(X + 11 + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, n, 1);
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y - 1, ' ', n, n, n * 2 + 1);
			}
		}
	}
	else {
		if (dst == 'A') {
			for (int y = endY; y <= Y - 1 - topA; y++) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
				if (y > 4) {
					cct_showch(X + 11 + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y + 1, ' ', n, n, n * 2 + 1);
				
			}
		}
		if (dst == 'B') {
			for (int y = endY; y <= Y - 1 - topB; y++) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
				if (y > 4) {
					cct_showch(X + 11 + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y + 1, ' ', n, n, n * 2 + 1);

			}
		}
		if (dst == 'C') {
			for (int y = endY; y <= Y -1 - topC; y++) {
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
				if (y > 4) {
					cct_showch(X + 11 + (dst - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (dst - 'A') * (LENGTH + 3), y + 1, ' ', n, n, n * 2 + 1);
			}
		}
	}
}

void plateMoveLevel(int n, char src, char dst)//盘子水平移动
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	const int endY = 2;
	int LENGTH = 23;
	int DIRECTION = (dst - src) > 0 ? 1 : -1; //判断移动方向    1--右移  -1--左移
	
	int x = X + 11 - n + (src - 'A') * (LENGTH + 3);
	while (1) {
		if (sleepTime != 0) {
			delay();
		}
		else
			Sleep(50);
		cct_showch(x, endY, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);//擦除原盘
		if (sleepTime != 0) {
			delay();
		}
		else
			Sleep(50);
		if (x == X + 11 - n + (dst - 'A') * (LENGTH + 3))
			break;
		cct_showch(x + DIRECTION, endY, ' ', n, n, n * 2 + 1);//打印新盘
		x += DIRECTION;
	}
}

void hanoiFinal(char select)//最终的函数，在菜单中调用
{
	int n;
	char src, dst, tmp;
	
	if (select != '5') {
		input(&n, &src, &tmp, &dst, select);
	}

	if (select == '1' || select == '2' || select == '3' || select == '4') {
		if (select == '4') {
			cct_cls();
			cout << "从 " << src << " 移动到 " << dst << " ，共 " << n << " 层，延时设置为 " << sleepTime << endl;
			cct_gotoxy(0, 20);
			cout << "初始:                ";
			printLevelStack();
			printVerticalStack(select);
		}
		hanoi(n, src, tmp, dst, select);
		if (select == '4')
			cct_gotoxy(0, 24);
	}
	else if (select == '5') {
		cct_cls();
		drawColumn();
		cct_gotoxy(0, 24);
	}
	else if (select == '6') {
		cct_cls();
		printMove(n, src, dst, select);
		drawColumn();
		drawPlate(n, src);
		cct_gotoxy(0, 24);
	}
	else if (select == '7') {
		cct_cls();

		cct_gotoxy(0, 0);
		cct_setcolor();
		cout << "从 " << src << " 移动到 " << dst << " , 共 " << n << " 层" << endl;

		drawColumn();
		drawPlate(n, src);

		hanoi(n, src, tmp, dst, select);

		cct_gotoxy(0, 24);
	}
	else if (select == '8') {
		cct_cls();

		cct_gotoxy(0, 0);
		cct_setcolor();
		cout << "从 " << src << " 移动到 " << dst << " , 共 " << n << " 层, 延时设置为 " << sleepTime << endl;

		cct_gotoxy(0, 32);
		cout << "初始:                ";
		printLevelStack();
		printVerticalStack(select);

		drawColumn();
		drawPlate(n, src);

		hanoi(n, src, tmp, dst, select);

		cct_gotoxy(0, 36);
	}
	else if (select == '9') {
		cct_cls();

		cct_gotoxy(0, 0);
		cct_setcolor();
		cout << "从 " << src << " 移动到 " << dst << " , 共 " << n << " 层" << endl;

		cct_gotoxy(0, 32);
		cout << "初始:                ";
		printLevelStack();
		printVerticalStack(select);

		drawColumn();
		drawPlate(n, src);

		game(n, src, dst, select);

		cct_gotoxy(0, 36);
	}
	
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();

	clearStack();
}

void game(int n, char src, char dst, char select)//对9特殊处理的函数
{
	char t[100];
	while (1) {
		int from = 1024, to = 1024;

		cct_gotoxy(0, 34);
		cct_setcolor();
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出):                       ";
		cct_gotoxy(60, 34);
		cin.getline(t, 100);
		if (t[0] == 'Q' || t[0] == 'q') {//游戏中止
			cout << "游戏中止！                ";
			return;
		}
		if (t[0] >= 'a' && t[0] <= 'c')//转大写
			t[0] -= 32;
		if (t[1] >= 'a' && t[1] <= 'c')
			t[1] -= 32;
		if (t[0] >= 'A' && t[0] <= 'C' && t[1] >= 'A' && t[1] <= 'C') {
			if (t[0] == 'A' && topA > 0)//给from填入当前栈的值
				from = stackA[topA - 1];
			else if (t[0] == 'B' && topB > 0)
				from = stackB[topB - 1];
			else if (t[0] == 'C' && topC > 0)
				from = stackC[topC - 1];

			else {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "原柱为空！                    ";
				continue;
			}

			if (t[1] == 'A' && topA > 0)
				to = stackA[topA - 1];
			else if (t[1] == 'B' && topB > 0)
				to = stackB[topB - 1];
			else if (t[1] == 'C' && topC > 0)
				to = stackC[topC - 1];

			if (to > from) {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "                                    ";
				printMove(from, t[0], t[1], select);//从t[0]移动到t[1],大小为from
			}
			else {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "大盘压小盘，非法移动！            ";
				continue;
			}

			if (checkFinish(n, dst)) {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "游戏结束！！！           ";
				return;
			}
		}
	}
}

bool checkFinish(int n, char dst)//游戏结束判定
{
	int temp = n;
	if (dst == 'A') {
		for (int i = 0; i < n; i++) {
			if (stackA[i] == temp)
				temp--;
			else
				return 0;
		}
		return 1;
	}
	else if (dst == 'B') {
		for (int i = 0; i < n; i++) {
			if (stackB[i] == temp)
				temp--;
			else
				return 0;
		}
		return 1;
	}
	else if (dst == 'C') {
		for (int i = 0; i < n; i++) {
			if (stackC[i] == temp)
				temp--;
			else
				return 0;
		}
		return 1;
	}
	return 0;
}