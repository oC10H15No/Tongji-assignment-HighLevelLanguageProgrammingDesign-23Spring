#include <iostream>
using namespace std;
int main()
{
	int i = 3, k;
	k = (i++) + (i++) + (i++);
	cout << k << endl;
	return 0;
}