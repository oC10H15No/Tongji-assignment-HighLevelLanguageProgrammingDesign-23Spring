/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：cls
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：const HANDLE hout
  返 回 值：void
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：输出菜单
  输入参数：void
  返 回 值：菜单项
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/

int menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl
		 << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl
		 << "3.用箭头键控制上下左右，边界停止" << endl
		 << "4.用箭头键控制上下左右，边界回绕" << endl
		 << "5.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界停止)" << endl
		 << "6.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界回绕)" << endl
		 << "0.退出" << endl
		 << "[请选择0-6] ";

	char nummern;
	int input;
	nummern = _getch();
	if (nummern == '0')
		return 0;
	input = nummern - '1' + 1;
	return input;
}


void move_by_ijkl_or_arrow(int input,int x,int y, HANDLE hout) {
	while (1) {
		int direction;
		direction = _getch();

		//检测输入空格，并消除字符
		if (direction == 32)
			putchar(' ');

		//检测输入 Q & q ,退出
		if (direction == 'Q' || direction == 'q') {
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单." << endl;

			//检测输入回车，按回车键返回菜单
			while (1) {
				input = _getch();
				if (input == 13) {
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}

		//1 2 5 6 
		if (input == 1 || input == 2 || input == 5 || input == 6) {
			//对箭头(224 + xx)进行特殊处理
			if (input == 5 || input == 6) {
				if (direction == 224)
					_getch();
			}

			if (direction == 'I' || direction == 'i') {
				if (y == 1) {
					if (input == 2 || input == 4 || input == 6)//跨越边界
						y = 17;
				}
				else
					y--;
			}
			if (direction == 'K' || direction == 'k') {
				if (y == 17) {
					if (input == 2 || input == 4 || input == 6)//跨越边界
						y = 1;
				}
				else
					y++;
			}
			if (direction == 'J' || direction == 'j') {
				if (x == 1) {
					if (input == 2 || input == 4 || input == 6)//跨越边界
						x = 69;
				}
				else
					x--;
			}
			if (direction == 'L' || direction == 'l') {
				if (x == 69) {
					if (input == 2 || input == 4 || input == 6)//跨越边界
						x = 1;
				}
				else
					x++;
			}
		}

		//3 4
		if (input == 3 || input == 4) {
			if (direction == 224) {
				direction = _getch();
				//上
				if (direction == 72) {
					if (y == 1) {
						if (input == 2 || input == 4 || input == 6)//跨越边界
							y = 17;
					}
					else
						y--;
				}
				//下
				if (direction == 80) {
					if (y == 17) {
						if (input == 2 || input == 4 || input == 6)//跨越边界
							y = 1;
					}
					else
						y++;
				}
				//左
				if (direction == 75) {
					if (x == 1) {
						if (input == 2 || input == 4 || input == 6)//跨越边界
							x = 69;
					}
					else
						x--;
				}
				
				//右
				if (direction == 77) {
					if (x == 69) {
						if (input == 2 || input == 4 || input == 6)//跨越边界
							x = 1;
					}
					else
						x++;
				}
			}
		}
		gotoxy(hout, x, y);
	}
	return;
}


int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int input;
	int x, y;
	while (1) {
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);               

		input = menu();

		if (input == 0) {
			cout << "0";
			return 0;//停止程序
		}
		if (input >= 1 && input <= 6) {	
			cls(hout);
			/* 显示初始的边框及其中的随机字符 */
			init_border(hout);

			x = 35;
			y = 9;

			gotoxy(hout, x, y);

			move_by_ijkl_or_arrow(input, x, y, hout);
		}
	}
	
	
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
//	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
//	cls(hout);

	/* 显示初始的边框及其中的随机字符 */
//	init_border(hout);

	//暂停
//	getchar();

//	gotoxy(hout, 0, 23);
//	cout << "游戏结束，按回车键退出." << endl;

	//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
//	getchar();

	return 0;
}

