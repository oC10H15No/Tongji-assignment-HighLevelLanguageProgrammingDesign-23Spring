/* 2351050 杨瑞晨 信05 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdio>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

#define UP   1
#define DOWN 0

char menu();
void hanoiFinal(char select);

void delay();
void move(char src, char dst);
void printLevelStack();
void printVerticalStack(char select);
void drawColumn();
void drawPlate(int n, char src);
void plateMoveVertical(int n, char src, char dst, bool direction);
void plateMoveLevel(int n, char src, char dst);
void clearStack(); 
void initial(int n, char src);
void printMove(int n, char src, char dst, char select);
void hanoi(int n, char src, char tmp, char dst, char select);
void input(int* n, char* src, char* tmp, char* dst, char select);
void game(int n, char src, char dst, char select);
bool checkFinish(int n, char dst);