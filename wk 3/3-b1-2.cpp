/*2351050 ��05 ����*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�     : " << 2 * pi * r << endl;
	cout << "Բ���     : " << pi * r * r << endl;
	cout << "Բ������ : " << 4 * pi * r * r << endl;
	cout << "Բ�����   : " << 4.0 / 3 * pi * r * r * r << endl;
	cout << "Բ�����   : " << pi * r * r * h << endl;
	return 0;
}