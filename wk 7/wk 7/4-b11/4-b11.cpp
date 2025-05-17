/* 2351050 ���� ��05 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��һ������order��ָ�� 1 ����/ 0 ����
   ***************************************************************************/

void print_line(char start_ch, char end_ch)
{
	cout << setfill('=') << setw((end_ch - start_ch) * 2 + 1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
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

	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch, current_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	print_line('A', end_ch);
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	print_line('A', end_ch);
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	print_line('A', end_ch);
	cout << "����(" << end_ch << "->A)" << endl;
	print_line('A', end_ch);
	print_tower('A', end_ch, 1);//��ӡ A~�����ַ���������
	print_tower('A', end_ch - 1, 0);//��ӡ A~�����ַ�-1�ĵ�����
	cout << endl;

	return 0;
}
