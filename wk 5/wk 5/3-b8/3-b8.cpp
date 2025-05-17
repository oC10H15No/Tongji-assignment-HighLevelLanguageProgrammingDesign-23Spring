/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x, n = 1;
	double t = 1, result = 0;
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;

	while (!(x >= -10 && x <= 65)) {
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
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