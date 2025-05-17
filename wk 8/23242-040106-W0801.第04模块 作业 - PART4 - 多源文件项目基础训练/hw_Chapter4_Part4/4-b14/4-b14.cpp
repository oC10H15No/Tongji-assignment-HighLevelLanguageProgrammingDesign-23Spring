/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

void nonEquation()
{
	cout << "不是一元二次方程" << endl;
}

void equalRoots(double a, double b)
{
	double root = -b / (2 * a);
	if (fabs(root) < 1e-6)
		root = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << root << endl;
}

void unequalRoots(double a, double b, double delta)
{
	double root1 = (-b + sqrt(delta)) / (2 * a);
	double root2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(root1) < 1e-6)
		root1 = 0;
	if (fabs(root2) < 1e-6)
		root2 = 0;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << ((root1 > root2) ? root1 : root2) << endl;
	cout << "x2=" << ((root1 < root2) ? root1 : root2) << endl;
}

void unequalIRoots(double a, double b, double delta)
{
	double realPart = -b / (2 * a);
	double imaginaryPart = fabs(sqrt(-delta) / (2 * a));
	if (fabs(realPart) < 1e-6)
		realPart = 0;
	if (fabs(imaginaryPart) < 1e-6)
		imaginaryPart = 0;
	cout << "有两个虚根：" << endl;
	if (realPart == 0) {
		cout << "x1=";
		if (imaginaryPart == 1)
			cout << "i" << endl;
		else 
			cout << imaginaryPart << "i" << endl;
		cout << "x2=";
		if (imaginaryPart == 1)
			cout << "-i" << endl;
		else
			cout << "-" << imaginaryPart << "i" << endl;
	}
	else {
		cout << "x1=" << realPart << "+";
		if (imaginaryPart == 1)
			cout << "i" << endl;
		else
			cout << imaginaryPart << "i" << endl;
		cout << "x2=" << realPart << "-";
		if (imaginaryPart == 1)
			cout << "i" << endl;
		else
			cout << imaginaryPart << "i" << endl;
	}
}

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