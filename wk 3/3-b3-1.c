/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	printf("请输入[0..100亿)之间的数字:\n");
	scanf("%lf", &num);

	num = num + 0.001;
	n1 = (int)(num / 1000000000) % 10;
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	n10 = (int)(fmod(num, 10));
	n11 = (int)(fmod(num, 1) * 10);
	n12 = (int)(fmod(num, 0.1) * 100);

	printf("十亿位 : %d\n", n1);
	printf("亿位   : %d\n", n2);
	printf("千万位 : %d\n", n3);
	printf("百万位 : %d\n", n4);
	printf("十万位 : %d\n", n5);
	printf("万位   : %d\n", n6);
	printf("千位   : %d\n", n7);
	printf("百位   : %d\n", n8);
	printf("十位   : %d\n", n9);
	printf("圆     : %d\n", n10);
	printf("角     : %d\n", n11);
	printf("分     : %d\n", n12);
	return 0;
}