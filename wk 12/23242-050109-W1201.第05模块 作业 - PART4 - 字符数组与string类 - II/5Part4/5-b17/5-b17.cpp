/* 2351050 杨瑞晨 信05 */
#include <iostream>
#include <ctime>
using namespace std;

#define NUM 10

int main()
{
	srand((unsigned int)(time(0)));

	static const char other[] = "!@#$%^&*-_=+,.?";

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int len, num_uppercase, num_lowercase, num_numbers, num_others;
	cin >> len >> num_uppercase >> num_lowercase >> num_numbers >> num_others;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (num_uppercase < 2) {
		cout << "大写字母个数[" << num_uppercase << "]不正确" << endl;
		return 0;
	}
	if (num_lowercase < 2) {
		cout << "小写字母个数[" << num_lowercase << "]不正确" << endl;
		return 0;
	}
	if (num_numbers < 2) {
		cout << "数字个数[" << num_numbers << "]不正确" << endl;
		return 0;
	}
	if (num_others < 2) {
		cout << "其它符号个数[" << num_others << "]不正确" << endl;
		return 0;
	}
	if (num_uppercase + num_lowercase + num_numbers + num_others > len) {
		cout << "所有字符类型之和[" << num_uppercase << "+" << num_lowercase << "+" << num_numbers << "+" << num_others << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	cout << len << " " << num_uppercase << " " << num_lowercase << " " << num_numbers << " " << num_others << endl;

	char password[NUM][17] = { 0 };
	for (int i = 0; i < NUM;) {
		int count_uppercase = num_uppercase;
		int count_lowercase = num_lowercase;
		int count_numbers = num_numbers;
		int count_others = num_others;
		int count_left = len - num_uppercase - num_lowercase - num_numbers - num_others;
		for (int j = 0; j < len; j++) {
			password[i][j] = rand() % 94 + 33;//33-126间的随机数

			if (password[i][j] >= 'A' && password[i][j] <= 'Z') {
				if (count_uppercase > 0)
					count_uppercase--;
				else
					count_left--;
			}
			else if (password[i][j] >= 'a' && password[i][j] <= 'z') {
				if (count_lowercase > 0)
					count_lowercase--;
				else
					count_left--;
			}
			else if (password[i][j] >= '0' && password[i][j] <= '9') {
				if (count_numbers > 0)
					count_numbers--;
				else
					count_left--;
			}
			else {
				for (int t = 0; t < sizeof(other) - 1; t++) {
					if (password[i][j] == other[t]) {
						if (count_others > 0)
							count_others--;
						else
							count_left--;
					}
				}
			}
			if (count_uppercase == 0 && count_lowercase == 0 && count_numbers == 0 && count_others == 0 && count_left == 0) {
				password[i][len] = '\0';
				i++;
				break;
			}
		}
		
	}

	for (int i = 0; i < NUM; i++) 
			cout << password[i] << endl;

	return 0;
}