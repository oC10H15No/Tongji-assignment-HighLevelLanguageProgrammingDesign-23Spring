/*2351050 ��05 ����*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const double pi = 3.14159;
	int a, b, theta;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> theta;
	float s =  a * b * (float)sin(theta * pi / 180) / 2;
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "���������Ϊ : " << fabs(s) << endl;
	return 0;
}