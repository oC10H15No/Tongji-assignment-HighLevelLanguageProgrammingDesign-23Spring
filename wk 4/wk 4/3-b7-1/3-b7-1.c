/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double money;
	int sum, n50, n20, n10, n5, n1, np5, np1, np05, np02, np01;
	printf("����������ֵ��\n");
	scanf("%lf", &money);
	money = money + 0.001;

	if (money >= 0.01 && money < 100) {
		n50 = (int)(money / 50);
		n20 = (int)((money - 50 * n50) / 20);
		n10 = (int)((money - 50 * n50 - 20 * n20) / 10);
		n5 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10) / 5);
		n1 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5) / 1);
		np5 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100) / 50;
		np1 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5) / 10;
		np05 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1) / 5;
		np02 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1 - 5 * np05) / 2;
		np01 = (int)((money - 50 * n50 - 20 * n20 - 10 * n10 - 5 * n5 - 1 * n1) * 100 - 50 * np5 - 10 * np1 - 5 * np05 - 2 * np02) / 1;

		sum = n50 + n20 + n10 + n5 + n1 + np5 + np1 + np05 + np02 + np01;
		printf("��%d�����㣬�������£�\n", sum);

		if (n50 != 0)
			printf("50Ԫ : %d��\n", n50);
		if (n20 != 0)
			printf("20Ԫ : %d��\n", n20);
		if (n10 != 0)
			printf("10Ԫ : %d��\n", n10);
		if (n5 != 0)
			printf("5Ԫ  : %d��\n", n5);
		if (n1 != 0)
			printf("1Ԫ  : %d��\n", n1);
		if (np5 != 0)
			printf("5��  : %d��\n", np5);
		if (np1 != 0)
			printf("1��  : %d��\n", np1);
		if (np05 != 0)
			printf("5��  : %d��\n", np05);
		if (np02 != 0)
			printf("2��  : %d��\n", np02);
		if (np01 != 0)
			printf("1��  : %d��\n", np01);
	}
	else {
		printf("�����������������\n");
	}

	return 0;
}