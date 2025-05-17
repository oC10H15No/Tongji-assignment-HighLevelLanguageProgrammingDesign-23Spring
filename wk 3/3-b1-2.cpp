/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长     : " << 2 * pi * r << endl;
	cout << "圆面积     : " << pi * r * r << endl;
	cout << "圆球表面积 : " << 4 * pi * r * r << endl;
	cout << "圆球体积   : " << 4.0 / 3 * pi * r * r * r << endl;
	cout << "圆柱体积   : " << pi * r * r * h << endl;
	return 0;
}