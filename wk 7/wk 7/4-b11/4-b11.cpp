/* 2351050 杨瑞晨 信05 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   有一个参数order，指定 1 正序/ 0 倒序
   ***************************************************************************/

void print_line(char start_ch, char end_ch)
{
	cout << setfill('=') << setw((end_ch - start_ch) * 2 + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
}

void print_space(char max_ch, char end_ch)
{
	if (max_ch != end_ch)
		cout << setfill(' ') << setw(max_ch - end_ch) << ' ';
	else
		return;
}

void print_letter(char start_ch, char end_ch)
{
	if (start_ch != end_ch) {
		cout << end_ch;
		print_letter(start_ch, end_ch - 1);
	}
	else {
		cout << start_ch;
		return;
	}
}

void print_letter_reverse(char start_ch, char end_ch)
{
	if (end_ch != start_ch) {
		cout << start_ch;
		print_letter_reverse(start_ch + 1, end_ch);
	}
	else {
		cout << end_ch;
		return;
	}
}

void print_tower(char start_ch, char end_ch, int order)
{
	static char max_ch = end_ch;
	if (order == 1) {
		if (end_ch > 'A') {
			print_tower(start_ch, end_ch - 1, order);
			print_space(max_ch, end_ch);
			print_letter(start_ch, end_ch);
			print_letter_reverse(start_ch + 1, end_ch);
			cout << endl;
		}
		else {
			print_space(max_ch, end_ch);
			cout << 'A' << endl;
			return;
		}
	}
	else {
		if (end_ch > 'A') {
			print_space(max_ch, end_ch);
			print_letter(start_ch, end_ch);
			print_letter_reverse(start_ch + 1, end_ch);
			cout << endl;
			print_tower(start_ch, end_ch - 1, order);
		}
		else if (end_ch == 'A' - 1)
			return;
		else {
			print_space(max_ch, end_ch);
			cout << 'A' << endl;
			return;
		}
	}

	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch, current_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	print_line('A', end_ch);
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	print_line('A', end_ch);
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	print_line('A', end_ch);
	cout << "菱形(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 1);//打印 A~结束字符的正三角
	print_tower('A', end_ch - 1, 0);//打印 A~结束字符-1的倒三角
	cout << endl;

	return 0;
}
