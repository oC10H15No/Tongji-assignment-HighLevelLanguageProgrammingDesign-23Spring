/*2351050 信05 杨瑞晨*/
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
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (y < 1900 || y > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (m < 1 || m > 12) {
			cout << "月份不正确，请重新输入" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d > 31) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d > 30) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else if (m == 2) {
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
				if (d < 1 || d > 29) {
					cout << "日不正确，请重新输入" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
			}
			else if (d < 1 || d >28 ) {
				cout << "日不正确，请重新输入" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		break;
	}

	w = zeller(y, m, d);
	cout << "星期";
	switch (w) {
		case 0:
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
	}
	cout << endl;

	return 0;
}