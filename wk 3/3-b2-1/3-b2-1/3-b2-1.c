/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, a, b, c, d, e;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &num);
	a = num % 10;
	b = num / 10 % 10;
	c = num / 100 % 10;
	d = num / 1000 % 10;
	e = num / 10000 % 10;
	printf("��λ : %d\n", e);
	printf("ǧλ : %d\n", d);
	printf("��λ : %d\n", c);
	printf("ʮλ : %d\n", b);
	printf("��λ : %d\n", a);
	return 0;
}