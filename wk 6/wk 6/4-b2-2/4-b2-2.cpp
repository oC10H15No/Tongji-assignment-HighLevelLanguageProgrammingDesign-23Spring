/*2351050 ��05 ����*/
#include <iostream>
#include <limits>
using namespace std;

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
	int y, m, d, w;

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;

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
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d > 31) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d > 30) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else if (m == 2) {
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
				if (d < 1 || d > 29) {
					cout << "�ղ���ȷ������������" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
			}
			else if (d < 1 || d >28 ) {
				cout << "�ղ���ȷ������������" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		break;
	}

	w = zeller(y, m, d);
	cout << "����";
	switch (w) {
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "һ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "��";
			break;
	}
	cout << endl;

	return 0;
}