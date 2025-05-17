/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
using namespace std;

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