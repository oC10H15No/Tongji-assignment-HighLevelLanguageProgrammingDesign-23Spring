/* 2351050 杨瑞晨 信05 */
#include <iostream>
using namespace std;

#define N 32

unsigned int BINtoDEC(char* p)
{
	unsigned int DEC = 0;
	while (*p != '\0') {
		DEC = DEC * 2 + (*p - '0');
		p++;
	}
	return DEC;
}

int main()
{
	char str[N + 1] = { 0 };
	cout << "请输入一个0/1组成的字符串，长度不超过" << N << endl;
	cin.getline(str, N + 1);

	unsigned int DEC = BINtoDEC(str);
	cout << DEC << endl;

	return 0;
}