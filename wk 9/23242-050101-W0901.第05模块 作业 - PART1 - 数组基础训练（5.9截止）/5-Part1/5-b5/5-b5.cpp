/*���� 2351050 ��05*/
#include <iostream>
using namespace std;

int main()
{
	cout << "������ɼ������1000������������������" << endl;
	int score[1000];
	for (int i = 0; i < 1000; i++) {
		cin >> score[i];
		if (score[i] < 0)
			break;
	}

	if (score[0] < 0) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "���������Ϊ:" << endl;
	for (int i = 0; i < 1000; i++) {
		if (score[i] < 0)
			break;
		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << score[i] << " ";
	}
	cout << endl;

	int sum[101] = { 0 };
	int rank = 1;
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j < 1000; j++) {
			if (score[j] == i)
				sum[i]++;
		}
	}
	for (int i = 100; i >= 0; i--) {
		if (sum[i]) {
			for (int j = 0; j < sum[i]; j++)
				cout << i << " " << rank << endl;
			rank += sum[i];
		}
	}

	return 0;
}