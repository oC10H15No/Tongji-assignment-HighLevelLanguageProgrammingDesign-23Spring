/*2351050 ��05 ����*/
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void calender(int year, int month, int week)
{
	/* ������Ӵ��� */

	cout << endl;

	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	/* ������Ӵ��� */
	int days;
	int line = 0;

	if (month == 2) {
		if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)      //��������
			days = 28;
		else
			days = 29;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)   //С��
		days = 30;
	else                                                              //����
		days = 31;

	for (int i = 0; i < week; i++) {
		cout << setw(8) << " ";
	}

	for (int i = 1; i <= days; i++) {
		cout << setw(4) << i << setw(4) << " ";
		week = (week + 1) % 7;
		if (week == 0 && i != days) {
			cout << endl;
		}
	}
	cout << endl;

	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
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

int main()
{
	int y, m, d = 1, w;

	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> y >> m;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (y < 1900 || y > 2100) {
			cout << "��ݲ���ȷ������������" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (m < 1 || m > 12) {
			cout << "�·ݲ���ȷ������������" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}

	w = zeller(y, m, d);
	calender(y, m, w);

	return 0;
}