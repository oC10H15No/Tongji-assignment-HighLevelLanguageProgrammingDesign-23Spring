/*2351050 信05 杨瑞晨*/
#include <iostream>
using namespace std;

int main()
{
	double money;
	int sum, n50, n20, n10, n5, n1, np5, np1, np05, np02, np01;
	cout << "请输入找零值：" << endl;
	cin >> money;
	money = money + 0.001;
	
	if (money >= 0.01 && money < 100) {
		n50 = (int)(money / 50);
		n20 = (int)((money - 50 * n50) / 20);
		n10 = (int)((money - 50 * n50 - 20 * n20) / 10);
		n5 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10) / 5);
		n1 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5) / 1);
		np5 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100) / 50;
		np1 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5) / 10;
		np05 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1) / 5;
		np02 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1 - 5 * np05) / 2;
		np01 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1 - 5 * np05 - 2 * np02) / 1;

		sum = n50 + n20 + n10 + n5 + n1 + np5 + np1 + np05 + np02 + np01;
		cout << "共" << sum << "张找零，具体如下：" << endl;

		if (n50 != 0)
			cout << "50元 : " << n50 << "张" << endl;
		if (n20 != 0)
			cout << "20元 : " << n20 << "张" << endl;
		if (n10 != 0)
			cout << "10元 : " << n10 << "张" << endl;
		if (n5 != 0)
			cout << "5元  : " << n5 << "张" << endl;
		if (n1 != 0)
			cout << "1元  : " << n1 << "张" << endl;
		if (np5 != 0)
			cout << "5角  : " << np5 << "张" << endl;
		if (np1 != 0)
			cout << "1角  : " << np1 << "张" << endl;
		if (np05 != 0)
			cout << "5分  : " << np05 << "张" << endl;
		if (np02 != 0)
			cout << "2分  : " << np02 << "张" << endl;
		if (np01 != 0)
			cout << "1分  : " << np01 << "张" << endl;
	}
	else {
		cout << "输入错误，请重新输入" << endl;
	}

	return 0;	
} 