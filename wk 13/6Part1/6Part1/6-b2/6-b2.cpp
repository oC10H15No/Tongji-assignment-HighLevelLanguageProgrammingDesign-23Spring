/* 2351050 杨瑞晨 信05 */
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
	cout << "请输入一个长度小于" << N << "的字符串（回文串）" << endl;
	fgets(str, N, stdin);

	int isPalindrome = -1;
	isPalindrome = palindrome(str);
	if (isPalindrome)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}