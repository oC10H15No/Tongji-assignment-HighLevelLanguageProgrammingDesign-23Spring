/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, a, b, c, d, e;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &num);
	a = num % 10;
	b = num / 10 % 10;
	c = num / 100 % 10;
	d = num / 1000 % 10;
	e = num / 10000 % 10;
	printf("万位 : %d\n", e);
	printf("千位 : %d\n", d);
	printf("百位 : %d\n", c);
	printf("十位 : %d\n", b);
	printf("个位 : %d\n", a);
	return 0;
}