/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

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