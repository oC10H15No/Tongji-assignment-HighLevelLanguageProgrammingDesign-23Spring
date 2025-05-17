/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

void equalRoots(double a, double b)
{
	double root = -b / (2 * a);
	if (fabs(root) < 1e-6)
		root = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << root << endl;
}