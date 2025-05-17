/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	cout << "请输入[0..100亿)之间的数字:" << endl;
	cin >> num;

	num = num + 0.001;
	n1 = (int)(num / 1000000000) % 10;
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	n10 = (int)(fmod(num, 10));
	n11 = (int)(fmod(num, 1) * 10);
	n12 = (int)(fmod(num, 0.1) * 100);


	cout << "十亿位 : " << n1 << endl;
	cout << "亿位   : " << n2 << endl;
	cout << "千万位 : " << n3 << endl;
	cout << "百万位 : " << n4 << endl;
	cout << "十万位 : " << n5 << endl;
	cout << "万位   : " << n6 << endl;
	cout << "千位   : " << n7 << endl;
	cout << "百位   : " << n8 << endl;
	cout << "十位   : " << n9 << endl;
	cout << "圆     : " << n10 << endl;
	cout << "角     : " << n11 << endl;
	cout << "分     : " << n12 << endl;
	return 0;
}