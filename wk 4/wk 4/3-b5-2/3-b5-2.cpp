/*2351050 ��05 ����*/
#include <iostream>
using namespace std;

int main()
{
	int year, month, day, n=0;
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;

	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {     //��ݷ�����
		if (month >= 1 && month <= 12) {                           //�·ݺϷ�
			if (month == 2) {                                                          //2��
				if (day >= 1 && day <= 28) {                                           //���ںϷ�
					n = day + 31;
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //С��
				if (day >= 1 && day <= 30) {                                           //���ںϷ�
					switch (month) {
						case 4:
							n = day + 31 + 28 + 31;
							break;
						case 6:
							n = day + 31 + 28 + 31 + 30 + 31;
							break;
						case 9:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
							break;
						case 11:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
							break;
						default:
							break;
					}
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else {                                                                     //����
				if (day >= 1 && day <= 31) {                                           //���ںϷ�
					switch (month) {
						case 1:
							n = day;
							break;
						case 3:
							n = day + 31 + 28;
							break;
						case 5:
							n = day + 31 + 28 + 31 + 30;
							break;
						case 7:
							n = day + 31 + 28 + 31 + 30 + 31 + 30;
							break;
						case 8:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
							break;
						case 10:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
							break;
						case 12:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
							break;
						default:
							break;
					}
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
		}
		else                                                       //�·ݷǷ�
			cout << "�������-�·ݲ���ȷ" << endl;
	}
	else {                                                         //���������
		if (month >= 1 && month <= 12) {                           //�·ݺϷ�
			if (month == 2) {                                                          //2��
				if (day >= 1 && day <= 29) {                                           //���ںϷ�
					n = day + 31;
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //С��
				if (day >= 1 && day <= 30) {                                           //���ںϷ�
					switch (month) {
						case 4:
							n = day + 31 + 29 + 31;
							break;
						case 6:
							n = day + 31 + 29 + 31 + 30 + 31;
							break;
						case 9:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
							break;
						case 11:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
							break;
						default:
							break;
					}
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else {                                                                     //����
				if (day >= 1 && day <= 31) {                                           //���ںϷ�
					switch (month) {
						case 1:
							n = day;
							break;
						case 3:
							n = day + 31 + 29;
							break;
						case 5:
							n = day + 31 + 29 + 31 + 30;
							break;
						case 7:
							n = day + 31 + 29 + 31 + 30 + 31 + 30;
							break;
						case 8:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
							break;
						case 10:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
							break;
						case 12:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
							break;
						default:
							break;
					}
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << n << "��" << endl;
				}
				else                                                                   //���ڷǷ�
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
		}
		else                                                       //�·ݷǷ�
			cout << "�������-�·ݲ���ȷ" << endl;
	}

	return 0;
}