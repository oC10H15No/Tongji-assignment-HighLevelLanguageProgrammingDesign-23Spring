/* 2351050 ÑîÈð³¿ ÐÅ05 */

#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdio>
#include <Windows.h>
#include <cmath>
#include "cmd_console_tools.h"
using namespace std;

#define NUM_MAX 10

//menu
char menu();
void magic_ball(char select);
void input(int* row, int* col, char select);
//base
void initial(int row, int col, int(*ball)[NUM_MAX], char select);
void print_stack(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX]);
void find_clear(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int* score);
void drop(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX]);
void fill_numbers(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX]);
void find_hint(int row, int col, int(*ball)[NUM_MAX], int(*hint)[NUM_MAX]);
//graph
void draw_border(int row, int col, bool divide, int sleep_time = -1);
void draw_ball(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX], int sleep_time = -1);
void draw_clear(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX]);
void draw_fill(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX]);
void draw_drop(int row, int col, bool divide, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX]);
//tools
void wait_for_enter();
void end();
bool is_all_zero(int row, int col, int arr[NUM_MAX][NUM_MAX]);
bool match(int row, int col, int ball[NUM_MAX][NUM_MAX], int x1, int y1, int x2, int y2);
void delay(int sleep_time);
int read_mouse(int row, int col, int(*ball)[NUM_MAX], int(*clear)[NUM_MAX], int(*hint)[NUM_MAX], const int length, char select, int* x, int* y);