/* 2351050 ���� ��05 */

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

#include "hanoi.h"

int topA = 0, topB = 0, topC = 0;
int stackA[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stackB[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stackC[10] = { 0,0,0,0,0,0,0,0,0,0 };
int countN = 0;
int sleepTime = 3;

void delay()//�ӳ�ʱ��
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

void move(char src, char dst)//ջ�������ƶ�
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

void printLevelStack()//��ӡˮƽ�ڲ�����
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

void printVerticalStack(char select) //��ӡ��ֱ�ڲ�����
{
	const int X = 28;
	int Y;
	if (select == '8' || select == '9')
		Y = 28;
	else
		Y = 15;
	
	//����
	cct_gotoxy(X - 1, Y + 1);
	cout << setw(25) << setfill('=') << "=" << endl;
	cct_gotoxy(X + 1, Y + 2);
	cout << setfill(' ') << "A         B         C";

	//��
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

void clearStack()//���ջ��������
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

void printMove(int n, char src, char dst, char select) //��ӡ�ƶ�
{
	const int X = 0;
	const int Y = 20;
	countN++;
	if (select == '1')
		cout << setw(2) << n << "# " << src << "---->" << dst << endl;
	else if (select == '2')
		cout << "��" << setiosflags(ios::right) << setw(4) << countN << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ") " << endl;
	else if (select == '3') {
		cout << "��" << setiosflags(ios::right) << setw(4) << countN << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		cout << endl;
	}
	else if (select == '4') {
		delay();
		cct_gotoxy(X, Y);
		cout << "��" << setiosflags(ios::right) << setw(4) << countN << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		printLevelStack();
		printVerticalStack(select);
	}
	else if (select == '6') {
		cout << "�� " << src << " �ƶ��� " << dst << " , �� " << n << " ��" << endl;
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
		cout << "��" << setiosflags(ios::right) << setw(4) << countN << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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
		cout << "��" << setiosflags(ios::right) << setw(4) << countN << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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
	//��ʼ��ջ
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

void hanoi(int n, char src, char tmp, char dst, char select)//1 2 3 4 7 8���õĵݹ麯��
{
	if (n == 1) {
		printMove(n, src, dst, select);
	}
	else {
		hanoi(n - 1, src, dst, tmp, select);
		if (select == '7')//7 ֻ�е�һ�����ƶ�
			return;
		printMove(n, src, dst, select);
		hanoi(n - 1, tmp, src, dst, select);
	}
}

void input(int *n, char *src, char *tmp, char *dst, char select) // 1 2 3 4 6 7 8 9 ���õ����뺯�� �β�Ϊָ���ͱ���
{
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
		cout << "��������ʼ��(A-C)" << endl;
		cin >> *src;
		if (cin.fail() || *src < 'A' || *src > 'c' || (*src > 'C' && *src < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (*src > 96) {
				*src = *src - 32;//Сд��ĸת��д
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> *dst;
		if (cin.fail() || *dst < 'A' || *dst > 'c' || (*dst > 'C' && *dst < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (*dst > 96) {
				*dst = *dst - 32;//Сд��ĸת��д
			}
			if (*src == *dst) {
				cout << "Ŀ����(" << *src << ")" << "��������ʼ��(" << *dst << ")��ͬ" << endl;
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
			cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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

void drawColumn()//������
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	int LENGTH = 23;
	const int bg_color = COLOR_HYELLOW;	//����Ϊ����ɫ
	const int fg_color = COLOR_HYELLOW;

	for (int i = 0; i < 3; i++) { //���������
		cct_showch(X + i * (LENGTH + 3), Y, ' ', bg_color, fg_color, LENGTH);
		Sleep(50);
		for (int j = 0; j < 12; j++) //��������
		{
			cct_showch(X + 11 + i * (LENGTH + 3), Y - j, ' ', bg_color, fg_color, 1);
			Sleep(50);
		}
	}
}

void drawPlate(int n, char src)//����ʼ����
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

void plateMoveVertical(int n, char src, char dst, bool direction)//���Ӵ�ֱ�ƶ�    direction: UP -- 1  DOWN -- 0
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
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);//����ԭ�е�����
				if (y > 4) {
					cct_showch(X + 11 + (src - 'A') * (LENGTH + 3), y, ' ', COLOR_HYELLOW, n, 1);//��������ɫ����
				}
				if (sleepTime != 0) {
					delay();
				}
				else
					Sleep(50);
				cct_showch(X + 11 - n + (src - 'A') * (LENGTH + 3), y - 1, ' ', n, n, n * 2 + 1);//��ӡ�µ�����
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

void plateMoveLevel(int n, char src, char dst)//����ˮƽ�ƶ�
{
	cct_setcursor(CURSOR_INVISIBLE);
	const int X = 2;
	const int Y = 16;
	const int endY = 2;
	int LENGTH = 23;
	int DIRECTION = (dst - src) > 0 ? 1 : -1; //�ж��ƶ�����    1--����  -1--����
	
	int x = X + 11 - n + (src - 'A') * (LENGTH + 3);
	while (1) {
		if (sleepTime != 0) {
			delay();
		}
		else
			Sleep(50);
		cct_showch(x, endY, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);//����ԭ��
		if (sleepTime != 0) {
			delay();
		}
		else
			Sleep(50);
		if (x == X + 11 - n + (dst - 'A') * (LENGTH + 3))
			break;
		cct_showch(x + DIRECTION, endY, ' ', n, n, n * 2 + 1);//��ӡ����
		x += DIRECTION;
	}
}

void hanoiFinal(char select)//���յĺ������ڲ˵��е���
{
	int n;
	char src, dst, tmp;
	
	if (select != '5') {
		input(&n, &src, &tmp, &dst, select);
	}

	if (select == '1' || select == '2' || select == '3' || select == '4') {
		if (select == '4') {
			cct_cls();
			cout << "�� " << src << " �ƶ��� " << dst << " ���� " << n << " �㣬��ʱ����Ϊ " << sleepTime << endl;
			cct_gotoxy(0, 20);
			cout << "��ʼ:                ";
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
		cout << "�� " << src << " �ƶ��� " << dst << " , �� " << n << " ��" << endl;

		drawColumn();
		drawPlate(n, src);

		hanoi(n, src, tmp, dst, select);

		cct_gotoxy(0, 24);
	}
	else if (select == '8') {
		cct_cls();

		cct_gotoxy(0, 0);
		cct_setcolor();
		cout << "�� " << src << " �ƶ��� " << dst << " , �� " << n << " ��, ��ʱ����Ϊ " << sleepTime << endl;

		cct_gotoxy(0, 32);
		cout << "��ʼ:                ";
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
		cout << "�� " << src << " �ƶ��� " << dst << " , �� " << n << " ��" << endl;

		cct_gotoxy(0, 32);
		cout << "��ʼ:                ";
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

void game(int n, char src, char dst, char select)//��9���⴦��ĺ���
{
	char t[100];
	while (1) {
		int from = 1024, to = 1024;

		cct_gotoxy(0, 34);
		cct_setcolor();
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�):                       ";
		cct_gotoxy(60, 34);
		cin.getline(t, 100);
		if (t[0] == 'Q' || t[0] == 'q') {//��Ϸ��ֹ
			cout << "��Ϸ��ֹ��                ";
			return;
		}
		if (t[0] >= 'a' && t[0] <= 'c')//ת��д
			t[0] -= 32;
		if (t[1] >= 'a' && t[1] <= 'c')
			t[1] -= 32;
		if (t[0] >= 'A' && t[0] <= 'C' && t[1] >= 'A' && t[1] <= 'C') {
			if (t[0] == 'A' && topA > 0)//��from���뵱ǰջ��ֵ
				from = stackA[topA - 1];
			else if (t[0] == 'B' && topB > 0)
				from = stackB[topB - 1];
			else if (t[0] == 'C' && topC > 0)
				from = stackC[topC - 1];

			else {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "ԭ��Ϊ�գ�                    ";
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
				printMove(from, t[0], t[1], select);//��t[0]�ƶ���t[1],��СΪfrom
			}
			else {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "����ѹС�̣��Ƿ��ƶ���            ";
				continue;
			}

			if (checkFinish(n, dst)) {
				cct_gotoxy(0, 35);
				cct_setcolor();
				cout << "��Ϸ����������           ";
				return;
			}
		}
	}
}

bool checkFinish(int n, char dst)//��Ϸ�����ж�
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