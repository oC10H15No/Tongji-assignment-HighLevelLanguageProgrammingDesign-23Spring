/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const double pi = 3.14159;
	int a, b, theta;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d%d%d", &a, &b, &theta);
	float s = a * b * (float)sin(theta * pi / 180) / 2;
	printf("���������Ϊ : %.3lf", fabs(s));
	return 0;
}