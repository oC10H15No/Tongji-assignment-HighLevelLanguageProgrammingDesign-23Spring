/*2351050 ��05 ����*/
#include <iostream>
using namespace std;

int main()
{
	int p[2] = { 1,2 };
	int* pp = p;
	int b = *(pp + 5) = 5;
	cout << b;
	return 0;
}
