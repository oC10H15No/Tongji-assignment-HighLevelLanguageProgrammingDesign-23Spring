/* 2351050 ���� ��05 */
#include <iostream>
using namespace std;

#define N 80

int palindrome(char* str) 
{
	int len = strlen(str);
	char* p = str, * t = str + len - 2;
	while (p < t) {
		if (*p != *t)
			return 0;
		p++;
		t--;
	}
	return 1;
}

int main()
{
	char str[N + 1];
	cout << "������һ������С��" << N << "���ַ��������Ĵ���" << endl;
	fgets(str, N, stdin);

	int isPalindrome = -1;
	isPalindrome = palindrome(str);
	if (isPalindrome)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}