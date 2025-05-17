/*杨瑞晨 2351050 信05*/
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int score[1000];
	for (int i = 0; i < 1000; i++) {
		cin >> score[i];
		if (score[i] < 0)
			break;
	}

	if (score[0] < 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;
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
	cout << "分数与名次的对应关系为:" << endl;
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