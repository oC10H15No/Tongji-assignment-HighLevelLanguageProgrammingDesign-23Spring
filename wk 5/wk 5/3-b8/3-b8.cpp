/*2351050 ��05 ����*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x, n = 1;
	double t = 1, result = 0;
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cin >> x;

	while (!(x >= -10 && x <= 65)) {
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		continue;
	}

	while (fabs(t) >= 1e-6) {
		result += t;
		t *= (double)x / n;
		n++;
	}

	cout << setprecision(10) << "e^" << x << "=" << result << endl;

	return 0;
}