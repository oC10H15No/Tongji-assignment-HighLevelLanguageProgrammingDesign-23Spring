/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const double pi = 3.14159;
	int a, b, theta;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> theta;
	float s =  a * b * (float)sin(theta * pi / 180) / 2;
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为 : " << fabs(s) << endl;
	return 0;
}