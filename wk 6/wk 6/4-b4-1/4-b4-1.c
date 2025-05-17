/*2351050 ��05 ����*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/

int menu()
{
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽�ֹͣ\n");
	printf("6.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽����\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6] ");

	char nummern;
	int input;
	nummern = _getch();
	if (nummern == '0')
		return 0;
	input = nummern - '1' + 1;
	return input;
}

void move_by_ijkl_or_arrow(int input, int x, int y, HANDLE hout) {
	while (1) {
		int direction;
		direction = _getch();

		//�������ո񣬲������ַ�
		if (direction == 32)
			putchar(' ');

		//������� Q & q ,�˳�
		if (direction == 'Q' || direction == 'q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.\n");

			//�������س������س������ز˵�
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
			//�Լ�ͷ(224 + xx)�������⴦��
			if (input == 5 || input == 6) {
				if (direction == 224)
					_getch();
			}

			if (direction == 'I' || direction == 'i') {
				if (y == 1) {
					if (input == 2 || input == 4 || input == 6)//��Խ�߽�
						y = 17;
				}
				else
					y--;
			}
			if (direction == 'K' || direction == 'k') {
				if (y == 17) {
					if (input == 2 || input == 4 || input == 6)//��Խ�߽�
						y = 1;
				}
				else
					y++;
			}
			if (direction == 'J' || direction == 'j') {
				if (x == 1) {
					if (input == 2 || input == 4 || input == 6)//��Խ�߽�
						x = 69;
				}
				else
					x--;
			}
			if (direction == 'L' || direction == 'l') {
				if (x == 69) {
					if (input == 2 || input == 4 || input == 6)//��Խ�߽�
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
				//��
				if (direction == 72) {
					if (y == 1) {
						if (input == 2 || input == 4 || input == 6)//��Խ�߽�
							y = 17;
					}
					else
						y--;
				}
				//��
				if (direction == 80) {
					if (y == 17) {
						if (input == 2 || input == 4 || input == 6)//��Խ�߽�
							y = 1;
					}
					else
						y++;
				}
				//��
				if (direction == 75) {
					if (x == 1) {
						if (input == 2 || input == 4 || input == 6)//��Խ�߽�
							x = 69;
					}
					else
						x--;
				}

				//��
				if (direction == 77) {
					if (x == 69) {
						if (input == 2 || input == 4 || input == 6)//��Խ�߽�
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	int input;
	int x, y;
	while (1) {
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		input = menu();

		if (input == 0) {
			printf("0");
			return 0;//ֹͣ����
		}
		if (input >= 1 && input <= 6) {
			cls(hout);
			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);

			x = 35;
			y = 9;

			gotoxy(hout, x, y);

			move_by_ijkl_or_arrow(input, x, y, hout);
		}
	}


	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
//	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
//	cls(hout);

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
//	init_border(hout);

	//��ͣ
//	getchar();

//	gotoxy(hout, 0, 23);
//	cout << "��Ϸ���������س����˳�." << endl;

	//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
//	getchar();

	return 0;
}