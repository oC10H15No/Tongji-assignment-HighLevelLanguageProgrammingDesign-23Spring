/* 2351050 ���� ��05 */
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
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����" << N << endl;
	cin.getline(str, N + 1);

	unsigned int DEC = BINtoDEC(str);
	cout << DEC << endl;

	return 0;
}