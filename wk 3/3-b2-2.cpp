/*2351050 ��05 ����*/
#include <iostream>
using namespace std;

int main()
{
	int num, a, b, c, d, e;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> num;
	a = num % 10;
	b = num / 10 % 10;
	c = num / 100 % 10;
	d = num / 1000 % 10;
	e = num / 10000 % 10;
	cout << "��λ : " << e << endl;
	cout << "ǧλ : " << d << endl;
	cout << "��λ : " << c << endl;
	cout << "ʮλ : " << b << endl;
	cout << "��λ : " << a << endl;
	return 0;
}