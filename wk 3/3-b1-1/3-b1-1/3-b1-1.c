/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const double pi = 3.14159;
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf%lf", &r, &h);
	printf("Բ�ܳ�     : %.2f\n", 2 * pi * r);
	printf("Բ���     : %.2f\n", pi * r * r);
	printf("Բ������ : %.2f\n", 4 * pi * r * r);
	printf("Բ�����   : %.2f\n", 4.0 / 3 * pi * r * r * r);
	printf("Բ�����   : %.2f\n", pi * r * r * h);
	return 0;
}