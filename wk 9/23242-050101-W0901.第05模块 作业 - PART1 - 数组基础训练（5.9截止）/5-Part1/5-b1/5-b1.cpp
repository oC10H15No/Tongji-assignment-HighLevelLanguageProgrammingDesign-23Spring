/*杨瑞晨 2351050 信05*/
#include <iostream>
using namespace std;

int main()
{
	
	int num[21];

	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (int i = 0; i < 20; i++) {
		cin >> num[i];
		if (num[i] == 0 || num[i] < 0)
			break;
	}
	
	if (num[0] <= 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
		

	cout << "原数组为：" << endl;
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
	cout << "请输入要插入的正整数" << endl;
	cin >> insert;
	cout << "插入后的数组为：" << endl;
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