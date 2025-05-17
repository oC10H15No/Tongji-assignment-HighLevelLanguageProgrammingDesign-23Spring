/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

void nonEquation();
void equalRoots(double a, double b);
void unequalRoots(double a, double b, double delta);
void unequalIRoots(double a, double b, double delta);

int main()
{
	double a, b, c, delta;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;


	if (a == 0)
		nonEquation();
	else if (delta == 0)
		equalRoots(a, b);
	else if (delta > 0)
		unequalRoots(a, b, delta);
	else if (delta < 0)
		unequalIRoots(a, b, delta);

	return 0;
}