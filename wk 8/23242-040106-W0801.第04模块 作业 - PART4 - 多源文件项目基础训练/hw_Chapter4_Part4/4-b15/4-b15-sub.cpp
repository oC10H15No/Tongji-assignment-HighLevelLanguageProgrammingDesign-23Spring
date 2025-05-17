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