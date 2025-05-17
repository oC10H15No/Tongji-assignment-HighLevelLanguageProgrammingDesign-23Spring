/* 2351050 杨瑞晨 信05 */

#include "magic_ball.h"

void magic_ball(char select)//主要处理函数，根据菜单项调用不同函数组合
{
	cct_cls();
	int row, col;
	input(&row, &col, select);

	int ball[NUM_MAX][NUM_MAX] = { 0 };
	int clear[NUM_MAX][NUM_MAX] = { 0 };
	int hint[NUM_MAX][NUM_MAX] = { 0 };

	int score = 0;

	initial(row, col, ball, select);
	
	if (select == '1' || select == '2' || select == '3' || select == '4' || select == '5' || select == '6' || select == '7') {
		cout << endl << "初始数组:";
		print_stack(row, col, ball, clear, hint);
	}
	if (select == '1' || select == '2' || select == '3') {
		cout << "按回车键进行寻找初始可消除项的操作...";
		wait_for_enter();
		find_clear(row, col, ball, clear, &score);
		if (is_all_zero(row, col, clear)) {
			cout << "初始已无可消除项";
		}
		else {
			cout << endl << "初始可消除项(不同色表示):";
			print_stack(row, col, ball, clear, hint);
		}
		cout << endl;
	}
	if (select == '2' || select == '3') {
		if (is_all_zero(row, col, clear)) {
			cout << "本小题无法测试，请再次运行" << endl;
			return;
		}
		else {
			while (1) {
				cout << "按回车键进行数组下落除0操作...";
				wait_for_enter();
				drop(row, col, ball, clear);
				cout << endl << "下落除0后的数组(不同色表示):";
				print_stack(row, col, ball, clear, hint);

				cout << "按回车键进行新值填充...";
				wait_for_enter();
				fill_numbers(row, col, ball, clear);
				cout << endl << "新值填充后的数组(不同色表示):";
				print_stack(row, col, ball, clear, hint);

				find_clear(row, col, ball, clear, &score);
				if (is_all_zero(row, col, clear)) {
					cout << "初始已无可消除项" << endl;
					break;
				}
				else {
					cout << endl << "初始可消除项(不同色表示):";
					print_stack(row, col, ball, clear, hint);
					continue;
				}
			}
		}
	}
	if (select == '3') {
		find_hint(row, col, ball, hint);
		cout << endl << "可选择的消除提示(不同色表示):";
		print_stack(row, col, ball, clear, hint);
	}
	if (select == '4' || select == '5' || select == '6' || select == '7' || select == '8' || select == '9') {
		if (select == '4' || select == '5') {
			cout << "按回车键显示图形...";
			wait_for_enter();
		}
		cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
		cct_cls();
		int wide = 40;
		int length;
		if (select == '4' || select == '6') {
			length = row + 6;
		}
		else {
			length = row + 6 + row - 1;
		}
		cct_setconsoleborder(wide, length, wide, length);
		cct_setfontsize("新宋体", 32);

		bool divide;
		if (select == '4' || select == '6')
			divide = 0;
		else
			divide = 1;

		cct_gotoxy(0, 0);
		cout << "屏幕：" << length << "行" << wide << "列";

		if (select == '4' || select == '5') {
			draw_border(row, col, divide, 15);
			draw_ball(row, col, divide, ball, clear, hint, 15);
		}
		if (select == '6') {
			draw_border(row, col, divide);
			find_clear(row, col, ball, clear, &score);
			if (is_all_zero(row, col, clear)) {
				cct_gotoxy(16, 0);
				cout << "(未找到初始可消除项)";
			}
			draw_ball(row, col, divide, ball, clear, hint);
		}
		if (select == '7') {
			draw_border(row, col, divide);
			find_clear(row, col, ball, clear, &score);
			draw_ball(row, col, divide, ball, clear, hint);
			while (1) {
				if (is_all_zero(row, col, clear)) {
					cct_gotoxy(16, 0);
					cout << "(未找到初始可消除项)";
					cct_gotoxy(0, length - 3);
					cout << "按回车键显示消除提示...            ";
					wait_for_enter();
					break;
				}
				else {
					draw_ball(row, col, divide, ball, clear, hint);
					cct_gotoxy(0, length - 3);
					cout << "按回车键进行消除及下落除0操作...     ";
					wait_for_enter();
					draw_clear(row, col, divide, ball, clear);
					draw_drop(row, col, divide, ball, clear);

					cct_gotoxy(0, length - 3);
					cout << "按回车键进行新值填充...             ";
					wait_for_enter();
					fill_numbers(row, col, ball, clear);
					draw_fill(row, col, divide, ball, clear);
					find_clear(row, col, ball, clear, &score);
					continue;
				}
			}
			find_hint(row, col, ball, hint);
			if (is_all_zero(row, col, hint)) {
				cct_gotoxy(16, 0);
				cout << "(无可消除项，游戏结束!)";
			}
			draw_ball(row, col, divide, ball, clear, hint);
		}
		if (select == '8' || select == '9') {
			cct_gotoxy(16, 0);
			cout << "(当前分数：" << score << " 右键退出)";

			int fake_score = 0;
			find_clear(row, col, ball, clear, &fake_score);
			draw_border(row, col, divide);
			draw_ball(row, col, divide, ball, clear, hint);
			while (!is_all_zero(row, col, clear)) {
					draw_ball(row, col, divide, ball, clear, hint);
					draw_clear(row, col, divide, ball, clear);
					cct_gotoxy(16, 0);
					//cout << "(当前分数：" << score << " 右键退出)";
					draw_drop(row, col, divide, ball, clear);
					Sleep(200);
					fill_numbers(row, col, ball, clear);
					draw_fill(row, col, divide, ball, clear);
					find_clear(row, col, ball, clear, &fake_score);
			}
			find_hint(row, col, ball, hint);
			draw_ball(row, col, divide, ball, clear, hint);

			//鼠标操作
			int X1 = -1, Y1 = -1, X2 = -1, Y2 = -1;
			while (1) {
				X1 = Y1 = X2 = Y2 = -1;
				int quit = read_mouse(row, col, ball, clear, hint, length, select, &X1, &Y1);
				if (quit == -1) {
					cct_gotoxy(0, length - 3);
					return;
				}
				if (X1 != -1 && Y1 != -1) {
					if (select == '8') {
						cct_gotoxy(0, length - 3);
						return;
					}
					cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "◎", ball[X1][Y1], COLOR_HWHITE, 1);
					cct_setcolor();
					read_mouse(row, col, ball, clear, hint, length, select, &X2, &Y2);
					if (quit == -1) {
						cct_gotoxy(0, length - 3);
						return;
					}
					if (X2 == X1 && Y2 == Y1) {
						cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "◎", ball[X1][Y1], COLOR_BLACK, 1);
						cct_setcolor();
						cct_gotoxy(0, length - 3);
						cout << "取消选择" << char(X1 + 'A') << "行" << Y1 + 1 << "列    ";
						Sleep(300);
						continue;
					}
					if (X2 != -1 && Y2 != -1) {
						if (match(row, col, ball, X1, Y1, X2, Y2) && ((fabs(X1 - X2) == 1 && Y1 == Y2) || (fabs(Y1 - Y2) == 1 && X1 == X2))) {
							cct_gotoxy(0, length - 3);
							cout << "交换" << char(X1 + 'A') << "行" << Y1 + 1 << "列";
							cout << " <=> " << char(X2 + 'A') << "行" << Y2 + 1 << "列";
							Sleep(300);
							hint[X1][Y1] = 0;
							hint[X2][Y2] = 0;
							//交换
							int temp = ball[X1][Y1];
							ball[X1][Y1] = ball[X2][Y2];
							ball[X2][Y2] = temp;

							draw_ball(row, col, divide, ball, clear, hint);
							Sleep(200);
							find_clear(row, col, ball, clear, &score);
							draw_ball(row, col, divide, ball, clear, hint);
							draw_clear(row, col, divide, ball, clear);
							cct_gotoxy(16, 0);
							cout << "(当前分数：" << score << " 右键退出)";
							draw_drop(row, col, divide, ball, clear);
							Sleep(200);
							fill_numbers(row, col, ball, clear);
							draw_fill(row, col, divide, ball, clear);
							find_clear(row, col, ball, clear, &score);
							while (!is_all_zero(row, col, clear)) {
								draw_ball(row, col, divide, ball, clear, hint);
								draw_clear(row, col, divide, ball, clear);
								cct_gotoxy(16, 0);
								cout << "(当前分数：" << score << " 右键退出)";
								draw_drop(row, col, divide, ball, clear);
								Sleep(200);
								fill_numbers(row, col, ball, clear);
								draw_fill(row, col, divide, ball, clear);
								find_clear(row, col, ball, clear, &score);
							}
							find_hint(row, col, ball, hint);
							if (is_all_zero(row, col, hint)) {
								draw_ball(row, col, divide, ball, clear, hint);
								cct_gotoxy(0, 0);
								cout << "无可消除项，游戏结束！最终分数：" << score << "      ";
								cct_gotoxy(0, length - 3);
								break;
							}
							draw_ball(row, col, divide, ball, clear, hint);
						}
						else {
							cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "◎", ball[X1][Y1], COLOR_BLACK, 1);
							cct_setcolor();
							cct_gotoxy(0, length - 3);
							cout << "不能交换" << char(X1 + 'A') << "行" << Y1 + 1 << "列";
							cout << " <=> " << char(X2 + 'A') << "行" << Y2 + 1 << "列";
							Sleep(400);
							continue;
						}
					}
				}
			}
		}
		cct_gotoxy(0, length - 3);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
}

void input(int* row, int* col, char select) // 共用的输入函数 形参为指针型变量
{
	while (1) {
		cout << "请输入行数(5-9):" << endl;
		cin >> *row;
		if (cin.fail() || *row < 5 || *row > 9) {
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
		cout << "请输入列数(5-9):" << endl;
		cin >> *col;
		if (cin.fail() || *col < 5 || *col > 9) {
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

char menu()
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_cls();

	cout << "-----------------------------------------------------------" << endl;
	cout << "1.内部数组，生成初始状态，寻找是否有初始可消除项" << endl;
	cout << "2.内部数组，消除初始可消除项后非0项下落并用0填充" << endl;
	cout << "3.内部数组，消除初始可消除项后查找消除提示" << endl;
	cout << "4.n*n的框架(无分隔线)，显示初始状态" << endl;
	cout << "5.n*n的框架(有分隔线)，显示初始状态" << endl;
	cout << "6.n*n的框架(有分隔线)，显示初始状态及初始可消除项" << endl;
	cout << "7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示" << endl;
	cout << "8.cmd图形界面完整版(有分割线，鼠标移动时显示坐标，右键退出)" << endl;
	cout << "9.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "[请选择:] ";

	char ret;
	while (1) {
		ret = _getch();
		if (cin.fail() || ret < '0' || ret > '9') {
			cin.clear();
			continue;
		}
		else
			break;
	}
	cout << ret << endl;
	return ret;
}