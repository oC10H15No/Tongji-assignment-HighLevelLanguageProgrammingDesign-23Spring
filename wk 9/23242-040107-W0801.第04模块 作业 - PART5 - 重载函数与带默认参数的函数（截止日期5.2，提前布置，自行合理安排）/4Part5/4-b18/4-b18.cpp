/*2351050 ��05 ����*/
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return max(c, max(a, b));
}

int max(int a, int b, int c, int d)
{
	return max(d, max(a, b, c));
}

int main()
{
	int n, a, b, c, d;
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (n == 2) {
			cin >> a >> b;
			if (cin.fail() || a <= 0 || b <= 0) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else
				break;
		}
		else if (n == 3) {
			cin >> a >> b >> c;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else
				break;
		}
		else if (n == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else
				break;
		}
		else {
			cout << "�����������" << endl;
			return 0;
		}
	}

	if (n == 2)
		cout << "max=" << max(a, b) << endl;
	else if (n == 3)
		cout << "max=" << max(a, b, c) << endl;
	else if (n == 4)
		cout << "max=" << max(a, b, c, d) << endl;
	
	return 0;
}