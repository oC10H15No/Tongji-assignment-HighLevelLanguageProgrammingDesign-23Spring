/* 2351050 ÑîÈð³¿ ÐÅ05 */
#include <iostream>
#include <ctime>
using namespace std;

#define NUM 10

int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";

	cin.ignore(INT_MAX, '\n');

	int len, num_uppercase, num_lowercase, num_numbers, num_others;
	cin >> len >> num_uppercase >> num_lowercase >> num_numbers >> num_others;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "´íÎó" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_uppercase < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_lowercase < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_numbers < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_others < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_uppercase + num_lowercase + num_numbers + num_others > len) {
		cout << "´íÎó" << endl;
		return 0;
	}

	char password[NUM][17] = { 0 };
	bool is_correct = 1;
	for (int i = 0; i < NUM; i++) {
		cin >> password[i];

		int count_uppercase = num_uppercase;
		int count_lowercase = num_lowercase;
		int count_numbers = num_numbers;
		int count_others = num_others;
		int count_left = len - num_uppercase - num_lowercase - num_numbers - num_others;
		for (int j = 0; j < len; j++) {
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
		}
		if (!(count_uppercase == 0 && count_lowercase == 0 && count_numbers == 0 && count_others == 0 && count_left == 0)) {
			is_correct = 0;
		}
	}
	
	if (is_correct)
		cout << "ÕýÈ·" << endl;
	else
		cout << "´íÎó" << endl;

	return 0;
}