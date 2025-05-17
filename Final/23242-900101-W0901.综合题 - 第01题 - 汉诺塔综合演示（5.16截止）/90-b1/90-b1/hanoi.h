/* 2351050 ���� ��05 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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