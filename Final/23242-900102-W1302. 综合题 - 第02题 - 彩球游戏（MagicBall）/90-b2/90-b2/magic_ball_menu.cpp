/* 2351050 ���� ��05 */

#include "magic_ball.h"

void magic_ball(char select)//��Ҫ�����������ݲ˵�����ò�ͬ�������
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
		cout << endl << "��ʼ����:";
		print_stack(row, col, ball, clear, hint);
	}
	if (select == '1' || select == '2' || select == '3') {
		cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
		wait_for_enter();
		find_clear(row, col, ball, clear, &score);
		if (is_all_zero(row, col, clear)) {
			cout << "��ʼ���޿�������";
		}
		else {
			cout << endl << "��ʼ��������(��ͬɫ��ʾ):";
			print_stack(row, col, ball, clear, hint);
		}
		cout << endl;
	}
	if (select == '2' || select == '3') {
		if (is_all_zero(row, col, clear)) {
			cout << "��С���޷����ԣ����ٴ�����" << endl;
			return;
		}
		else {
			while (1) {
				cout << "���س����������������0����...";
				wait_for_enter();
				drop(row, col, ball, clear);
				cout << endl << "�����0�������(��ͬɫ��ʾ):";
				print_stack(row, col, ball, clear, hint);

				cout << "���س���������ֵ���...";
				wait_for_enter();
				fill_numbers(row, col, ball, clear);
				cout << endl << "��ֵ���������(��ͬɫ��ʾ):";
				print_stack(row, col, ball, clear, hint);

				find_clear(row, col, ball, clear, &score);
				if (is_all_zero(row, col, clear)) {
					cout << "��ʼ���޿�������" << endl;
					break;
				}
				else {
					cout << endl << "��ʼ��������(��ͬɫ��ʾ):";
					print_stack(row, col, ball, clear, hint);
					continue;
				}
			}
		}
	}
	if (select == '3') {
		find_hint(row, col, ball, hint);
		cout << endl << "��ѡ���������ʾ(��ͬɫ��ʾ):";
		print_stack(row, col, ball, clear, hint);
	}
	if (select == '4' || select == '5' || select == '6' || select == '7' || select == '8' || select == '9') {
		if (select == '4' || select == '5') {
			cout << "���س�����ʾͼ��...";
			wait_for_enter();
		}
		cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
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
		cct_setfontsize("������", 32);

		bool divide;
		if (select == '4' || select == '6')
			divide = 0;
		else
			divide = 1;

		cct_gotoxy(0, 0);
		cout << "��Ļ��" << length << "��" << wide << "��";

		if (select == '4' || select == '5') {
			draw_border(row, col, divide, 15);
			draw_ball(row, col, divide, ball, clear, hint, 15);
		}
		if (select == '6') {
			draw_border(row, col, divide);
			find_clear(row, col, ball, clear, &score);
			if (is_all_zero(row, col, clear)) {
				cct_gotoxy(16, 0);
				cout << "(δ�ҵ���ʼ��������)";
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
					cout << "(δ�ҵ���ʼ��������)";
					cct_gotoxy(0, length - 3);
					cout << "���س�����ʾ������ʾ...            ";
					wait_for_enter();
					break;
				}
				else {
					draw_ball(row, col, divide, ball, clear, hint);
					cct_gotoxy(0, length - 3);
					cout << "���س������������������0����...     ";
					wait_for_enter();
					draw_clear(row, col, divide, ball, clear);
					draw_drop(row, col, divide, ball, clear);

					cct_gotoxy(0, length - 3);
					cout << "���س���������ֵ���...             ";
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
				cout << "(�޿��������Ϸ����!)";
			}
			draw_ball(row, col, divide, ball, clear, hint);
		}
		if (select == '8' || select == '9') {
			cct_gotoxy(16, 0);
			cout << "(��ǰ������" << score << " �Ҽ��˳�)";

			int fake_score = 0;
			find_clear(row, col, ball, clear, &fake_score);
			draw_border(row, col, divide);
			draw_ball(row, col, divide, ball, clear, hint);
			while (!is_all_zero(row, col, clear)) {
					draw_ball(row, col, divide, ball, clear, hint);
					draw_clear(row, col, divide, ball, clear);
					cct_gotoxy(16, 0);
					//cout << "(��ǰ������" << score << " �Ҽ��˳�)";
					draw_drop(row, col, divide, ball, clear);
					Sleep(200);
					fill_numbers(row, col, ball, clear);
					draw_fill(row, col, divide, ball, clear);
					find_clear(row, col, ball, clear, &fake_score);
			}
			find_hint(row, col, ball, hint);
			draw_ball(row, col, divide, ball, clear, hint);

			//������
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
					cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "��", ball[X1][Y1], COLOR_HWHITE, 1);
					cct_setcolor();
					read_mouse(row, col, ball, clear, hint, length, select, &X2, &Y2);
					if (quit == -1) {
						cct_gotoxy(0, length - 3);
						return;
					}
					if (X2 == X1 && Y2 == Y1) {
						cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "��", ball[X1][Y1], COLOR_BLACK, 1);
						cct_setcolor();
						cct_gotoxy(0, length - 3);
						cout << "ȡ��ѡ��" << char(X1 + 'A') << "��" << Y1 + 1 << "��    ";
						Sleep(300);
						continue;
					}
					if (X2 != -1 && Y2 != -1) {
						if (match(row, col, ball, X1, Y1, X2, Y2) && ((fabs(X1 - X2) == 1 && Y1 == Y2) || (fabs(Y1 - Y2) == 1 && X1 == X2))) {
							cct_gotoxy(0, length - 3);
							cout << "����" << char(X1 + 'A') << "��" << Y1 + 1 << "��";
							cout << " <=> " << char(X2 + 'A') << "��" << Y2 + 1 << "��";
							Sleep(300);
							hint[X1][Y1] = 0;
							hint[X2][Y2] = 0;
							//����
							int temp = ball[X1][Y1];
							ball[X1][Y1] = ball[X2][Y2];
							ball[X2][Y2] = temp;

							draw_ball(row, col, divide, ball, clear, hint);
							Sleep(200);
							find_clear(row, col, ball, clear, &score);
							draw_ball(row, col, divide, ball, clear, hint);
							draw_clear(row, col, divide, ball, clear);
							cct_gotoxy(16, 0);
							cout << "(��ǰ������" << score << " �Ҽ��˳�)";
							draw_drop(row, col, divide, ball, clear);
							Sleep(200);
							fill_numbers(row, col, ball, clear);
							draw_fill(row, col, divide, ball, clear);
							find_clear(row, col, ball, clear, &score);
							while (!is_all_zero(row, col, clear)) {
								draw_ball(row, col, divide, ball, clear, hint);
								draw_clear(row, col, divide, ball, clear);
								cct_gotoxy(16, 0);
								cout << "(��ǰ������" << score << " �Ҽ��˳�)";
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
								cout << "�޿��������Ϸ���������շ�����" << score << "      ";
								cct_gotoxy(0, length - 3);
								break;
							}
							draw_ball(row, col, divide, ball, clear, hint);
						}
						else {
							cct_showstr(2 + Y1 * (divide + 1) * 2, 2 + X1 * (divide + 1), "��", ball[X1][Y1], COLOR_BLACK, 1);
							cct_setcolor();
							cct_gotoxy(0, length - 3);
							cout << "���ܽ���" << char(X1 + 'A') << "��" << Y1 + 1 << "��";
							cout << " <=> " << char(X2 + 'A') << "��" << Y2 + 1 << "��";
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

void input(int* row, int* col, char select) // ���õ����뺯�� �β�Ϊָ���ͱ���
{
	while (1) {
		cout << "����������(5-9):" << endl;
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
		cout << "����������(5-9):" << endl;
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
	cout << "1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������" << endl;
	cout << "2.�ڲ����飬������ʼ����������0�����䲢��0���" << endl;
	cout << "3.�ڲ����飬������ʼ������������������ʾ" << endl;
	cout << "4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬" << endl;
	cout << "5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬" << endl;
	cout << "6.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬����ʼ��������" << endl;
	cout << "7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ" << endl;
	cout << "8.cmdͼ�ν���������(�зָ��ߣ�����ƶ�ʱ��ʾ���꣬�Ҽ��˳�)" << endl;
	cout << "9.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "[��ѡ��:] ";

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