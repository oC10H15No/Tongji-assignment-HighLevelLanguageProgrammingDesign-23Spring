/*2351050 信05 杨瑞晨*/
#include <iostream>
using namespace std;

int main()
{
	int num, a, b, c, d, e;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> num;
	a = num % 10;
	b = num / 10 % 10;
	c = num / 100 % 10;
	d = num / 1000 % 10;
	e = num / 10000 % 10;
	cout << "万位 : " << e << endl;
	cout << "千位 : " << d << endl;
	cout << "百位 : " << c << endl;
	cout << "十位 : " << b << endl;
	cout << "个位 : " << a << endl;
	return 0;
}