/*2351050 ��05 ����*/
#include <iostream>
#include <iomanip>
using namespace std;

#define MONTH i * 3 + j 

int leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

int zeller(int y, int m, int d)
{
	int c, w;

	if (m == 1 || m == 2) {
		m += 12;
		y -= 1;
	}

	c = y / 100;
	y = y % 100;

	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	while (w < 0) {
		w += 7;
	}
	w = w % 7;

	return w;
}
void calendar(int year)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int date[12];
	for (int t = 0; t < 12; t++)
		date[t] = 1;
	int end_flag[12];
	for (int t = 0; t < 12; t++)
		end_flag[t] = 0;

	if (leapYear(year))
		days[1] = 29;

	cout << year << "�������:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << resetiosflags(ios::left) << setiosflags(ios::right) << endl;
		cout << setw(13) << i * 3 + 1 << "��" << setw(30) << i * 3 + 2 << "��" << setw(30) << i * 3 + 3 << "��" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     ";
		cout << "Sun Mon Tue Wed Thu Fri Sat     "; 
		cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
		cout << resetiosflags(ios::right) << setiosflags(ios::left);
		
		int j = 0;
		while (date[i * 3] <= days[i * 3] || date[i * 3 + 1] <= days[i * 3 + 1] || date[i * 3 + 2] <= days[i * 3 + 2]) {
			while (date[MONTH] <= days[MONTH]) {
				//��ӡ1��ǰ�Ŀո�
				if (date[MONTH] == 1) {
					for (int k = 0; k < zeller(year, MONTH + 1, date[MONTH]); k++)//ʹ��zellerʱ�·�+1�Ա�֤��ȷ
						cout << "    ";
				}
				//��ӡ����
				cout << setw(4) << date[MONTH];
				date[MONTH]++;
				if (date[MONTH] <= days[MONTH] && zeller(year, MONTH + 1, date[MONTH]) == 0){//δ��ӡ�� �� ��һ��Ϊ����ʱ����ѭ��
					if (j < 2)
						cout << "    ";
					break;
				 }
			}
			//���·�δ��ӡ����Ҫ��ӡ���Ѵ�ӡ��ʱ����ӡ�ո� 4*8
			if (end_flag[MONTH] == 1) {
				cout << "                                ";
			}
			//����δ��ӡ��ʱ�����м�Ҫ��ӡ��
			if (end_flag[MONTH] == 0 && date[MONTH] == days[MONTH] + 1) {
				//��ӡ����Ŀո��Զ���
				for (int k = 0; k < 6 - zeller(year, MONTH + 1, days[MONTH]); k++)
					cout << "    ";
				if (j < 2)
					cout << "    ";
				//����ĩ�����1
				end_flag[MONTH] = 1;
			}
			//ÿ3�´�ӡ����
			if (j == 2  && (date[i * 3] <= days[i * 3] || date[i * 3 + 1] <= days[i * 3 + 1] || date[i * 3 + 2] <= days[i * 3 + 2]))
				cout << endl;
			
			j = (j + 1) % 3;
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int year;

	while (1) {
		cout << "���������[1900-2100]" << endl;
		cin >> year;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100) {
			continue;
		}
		break;
	}

	calendar(year);

	cout << endl;

	return 0;
}