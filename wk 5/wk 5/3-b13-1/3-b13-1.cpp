/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <iomanip>
#include <limits> 
using namespace std;

int main()
{
	int year, month, week;

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;

		if (cin.fail()) {
			cin.clear();                                               //清空输入缓冲区
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  //忽略错误值
			cout << "输入非法，请重新输入" << endl;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;

		if (cin.fail()) {
			cin.clear();                                               //清空输入缓冲区
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  //忽略错误值
			cout << "输入非法，请重新输入" << endl;
		}
		else if (week >= 0 && week <= 6)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;

	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	
	int days;
	int line = 0;

	if (month == 2) {
		if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)      //不是闰年
			days = 28;
		else
			days = 29;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)   //小月
		days = 30;
	else                                                              //大月
		days = 31;

	char space = ' ';
	switch (week) {
		case 0:
			break;
		case 1:
			cout << setiosflags(ios::right) << setw(8) << space;
			break;
		case 2:
			cout << setiosflags(ios::right) << setw(16) << space;
			break;
		case 3:
			cout << setiosflags(ios::right) << setw(24) << space;
			break; 
		case 4:
			cout << setiosflags(ios::right) << setw(32) << space;
			break;
		case 5:
			cout << setiosflags(ios::right) << setw(40) << space;
			break;
		case 6:
			cout << setiosflags(ios::right) << setw(48) << space;
			break;
		default:
			break;
	}

	for (int i = 1; i <= days; i++)
		if (1) {
			cout << setw(4) << i << setw(4) << space;
			line++;
			if ((week + line) % 7 == 0) {
				cout << endl;
			}
		}
	
	cout << endl;

	return 0;
}
