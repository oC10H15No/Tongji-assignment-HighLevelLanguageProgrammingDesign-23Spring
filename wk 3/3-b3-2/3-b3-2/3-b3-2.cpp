/*2351050 ��05 ����*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	cout << "������[0..100��)֮�������:" << endl;
	cin >> num;

	num = num + 0.001;
	n1 = (int)(num / 1000000000) % 10;
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	n10 = (int)(fmod(num, 10));
	n11 = (int)(fmod(num, 1) * 10);
	n12 = (int)(fmod(num, 0.1) * 100);


	cout << "ʮ��λ : " << n1 << endl;
	cout << "��λ   : " << n2 << endl;
	cout << "ǧ��λ : " << n3 << endl;
	cout << "����λ : " << n4 << endl;
	cout << "ʮ��λ : " << n5 << endl;
	cout << "��λ   : " << n6 << endl;
	cout << "ǧλ   : " << n7 << endl;
	cout << "��λ   : " << n8 << endl;
	cout << "ʮλ   : " << n9 << endl;
	cout << "Բ     : " << n10 << endl;
	cout << "��     : " << n11 << endl;
	cout << "��     : " << n12 << endl;
	return 0;
}