/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const double pi = 3.14159;
	int a, b, theta;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d%d%d", &a, &b, &theta);
	float s = a * b * (float)sin(theta * pi / 180) / 2;
	printf("三角形面积为 : %.3lf", fabs(s));
	return 0;
}