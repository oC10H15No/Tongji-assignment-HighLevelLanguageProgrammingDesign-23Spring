/*2351050 ��05 ����*/
#include <iostream>
#include <cmath>
using namespace std;

void equalRoots(double a, double b)
{
	double root = -b / (2 * a);
	if (fabs(root) < 1e-6)
		root = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << root << endl;
}