/* 2351050 杨瑞晨 信05 */
#include <iostream>
using namespace std;

int main()
{
	char str[3][128] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << "请输入第" << i + 1 << "行" << endl;
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
	
	cout << "大写 : " << result[0] << endl;
	cout << "小写 : " << result[1] << endl;
	cout << "数字 : " << result[2] << endl;
	cout << "空格 : " << result[3] << endl;
	cout << "其它 : " << result[4] << endl;

	return 0;
}
