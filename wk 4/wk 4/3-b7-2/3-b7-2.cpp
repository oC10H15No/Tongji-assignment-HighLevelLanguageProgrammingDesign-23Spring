/*2351050 ��05 ����*/
#include <iostream>
using namespace std;

int main()
{
	double money;
	int sum, n50, n20, n10, n5, n1, np5, np1, np05, np02, np01;
	cout << "����������ֵ��" << endl;
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
		cout << "��" << sum << "�����㣬�������£�" << endl;

		if (n50 != 0)
			cout << "50Ԫ : " << n50 << "��" << endl;
		if (n20 != 0)
			cout << "20Ԫ : " << n20 << "��" << endl;
		if (n10 != 0)
			cout << "10Ԫ : " << n10 << "��" << endl;
		if (n5 != 0)
			cout << "5Ԫ  : " << n5 << "��" << endl;
		if (n1 != 0)
			cout << "1Ԫ  : " << n1 << "��" << endl;
		if (np5 != 0)
			cout << "5��  : " << np5 << "��" << endl;
		if (np1 != 0)
			cout << "1��  : " << np1 << "��" << endl;
		if (np05 != 0)
			cout << "5��  : " << np05 << "��" << endl;
		if (np02 != 0)
			cout << "2��  : " << np02 << "��" << endl;
		if (np01 != 0)
			cout << "1��  : " << np01 << "��" << endl;
	}
	else {
		cout << "�����������������" << endl;
	}

	return 0;	
} 