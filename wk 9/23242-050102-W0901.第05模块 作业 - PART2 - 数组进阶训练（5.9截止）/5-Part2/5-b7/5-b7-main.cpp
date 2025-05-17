/*2351050 杨瑞晨 信05*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;
#include "5-b7.h"

int topA = 0, topB = 0, topC = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
static int sleepTime;
static int displayInternal;


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
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(100);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(1);
			break;
		default:
			break;
	}
}

void move(char src, char dst)//数字移动
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

void printLevelStack()//打印内部数组
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

void initial(int n, char src, char dst)//初始化栈
{
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

void printMove(int n, char src, char dst)
{
	cct_gotoxy(20, 26);
	static int count = 0;
	count++;
	cout << "第" << setiosflags(ios::right) << setw(4) << count << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
}

void printVerticalStack()
{
	const int X = 10;
	const int Y = 20;
	//塔底
	cct_gotoxy(X - 1, Y + 1);
	cout << setw(25) << setfill('=') << "=" << endl;
	cct_gotoxy(X + 1, Y + 2);
	cout << setfill(' ') << "A         B         C";

	//塔
	int i;
	for (i = 0; i < 10 ; i++) {
		cct_gotoxy(X, Y - i);
		if (stackA[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackA[i];
	}
	for (i = 0; i < 10 ; i++) {
		cct_gotoxy(X + 10, Y - i);
		if (stackB[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackB[i];
	}
	for (i = 0; i < 10 ; i++) {
		cct_gotoxy(X + 20, Y - i);
		if (stackC[i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stackC[i];
	}
}

void hanoi(int n, char src, char tmp, char dst)
{
	
	if (n == 1) {
		delay();
		printMove(n, src, dst);
		move(src, dst);
		if (displayInternal) {
			printLevelStack();
		}
		delay();
		printVerticalStack();
		
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		delay();
		printMove(n, src, dst);
		move(src, dst);
		if (displayInternal) {
			printLevelStack();
		}
		delay();
		printVerticalStack();
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	char src, dst, tmp;
	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail() || n < 1 || n > 10) {
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
		cin >> src;
		if (cin.fail() || src < 'A' || src > 'c' || (src > 'C' && src < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (src > 96) {
				src = src - 32;//小写字母转大写
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (cin.fail() || dst < 'A' || dst > 'c' || (dst > 'C' && dst < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (dst > 96) {
				dst = dst - 32;//小写字母转大写
			}
			if (src == dst) {
				cout << "目标柱(" << src << ")" << "不能与起始柱(" << dst << ")相同" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}

	tmp = 3 * 'B' - src - dst;
	
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
	while (1) {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> displayInternal;
		if (cin.fail() || displayInternal < 0 || displayInternal > 1) {
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

	cct_cls();//清屏
	cout << "从 " << src << " 移动到 " << dst << " ，共 " << n << " 层，延时设置为 " << sleepTime << " ，"; 
	if (!displayInternal)
		cout << "不";
	else
		;
	cout << "显示内部数组值" << endl;

	initial(n, src, dst);

	printVerticalStack();//汉诺塔

	if (displayInternal) {
		cct_gotoxy(20, 26);
		cout << "初始:" << setw(16) << " ";
		printLevelStack();
	}
	
	hanoi(n, src, tmp, dst);

	cct_gotoxy(0, 28);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}