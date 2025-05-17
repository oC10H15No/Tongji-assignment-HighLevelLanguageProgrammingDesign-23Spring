/*2351050 ��05 ����*/
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;

void nonEquation();
void equalRoots();
void unequalRoots();
void unequalIRoots();

int main()
{
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;


	if (a == 0)
		nonEquation();
	else if (delta == 0)
		equalRoots();
	else if (delta > 0)
		unequalRoots();
	else if (delta < 0)
		unequalIRoots();

	return 0;
}