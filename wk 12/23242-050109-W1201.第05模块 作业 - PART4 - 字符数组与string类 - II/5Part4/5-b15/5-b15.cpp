/* 2351050 ���� ��05 */
#include <iostream>
using namespace std;

int main()
{
	char str[3][128] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);
	}

	int result[5] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				result[0]++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				result[1]++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				result[2]++;
			else if (str[i][j] == ' ')
				result[3]++;
			else
				result[4]++;
		}
	}
	
	cout << "��д : " << result[0] << endl;
	cout << "Сд : " << result[1] << endl;
	cout << "���� : " << result[2] << endl;
	cout << "�ո� : " << result[3] << endl;
	cout << "���� : " << result[4] << endl;

	return 0;
}
