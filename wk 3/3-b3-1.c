/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	printf("������[0..100��)֮�������:\n");
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

	printf("ʮ��λ : %d\n", n1);
	printf("��λ   : %d\n", n2);
	printf("ǧ��λ : %d\n", n3);
	printf("����λ : %d\n", n4);
	printf("ʮ��λ : %d\n", n5);
	printf("��λ   : %d\n", n6);
	printf("ǧλ   : %d\n", n7);
	printf("��λ   : %d\n", n8);
	printf("ʮλ   : %d\n", n9);
	printf("Բ     : %d\n", n10);
	printf("��     : %d\n", n11);
	printf("��     : %d\n", n12);
	return 0;
}