/*���� 2351050 ��05*/
#include <iostream>
using namespace std;

int main()
{
	
	int num[21];

	cout << "��������������������������20������0������������" << endl;
	for (int i = 0; i < 20; i++) {
		cin >> num[i];
		if (num[i] == 0 || num[i] < 0)
			break;
	}
	
	if (num[0] <= 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
		

	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] <= 0)
			break;
		cout << num[i] << " ";
	}
	cout << endl;

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	int insert;
	int outputInsert = 0;
	cout << "������Ҫ�����������" << endl;
	cin >> insert;
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < 20; i++) {
		if (num[i] <= 0)
			break;
		if (num[i] > insert && outputInsert == 0) {
			cout << insert << " ";
			outputInsert = 1;
		}
		cout << num[i] << " ";
	}
	if (outputInsert == 0)
		cout << insert << " ";
	cout << endl;

	return 0;
}