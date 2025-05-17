/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double money;
	int sum, n50, n20, n10, n5, n1, np5, np1, np05, np02, np01;
	printf("请输入找零值：\n");
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
		printf("共%d张找零，具体如下：\n", sum);

		if (n50 != 0)
			printf("50元 : %d张\n", n50);
		if (n20 != 0)
			printf("20元 : %d张\n", n20);
		if (n10 != 0)
			printf("10元 : %d张\n", n10);
		if (n5 != 0)
			printf("5元  : %d张\n", n5);
		if (n1 != 0)
			printf("1元  : %d张\n", n1);
		if (np5 != 0)
			printf("5角  : %d张\n", np5);
		if (np1 != 0)
			printf("1角  : %d张\n", np1);
		if (np05 != 0)
			printf("5分  : %d张\n", np05);
		if (np02 != 0)
			printf("2分  : %d张\n", np02);
		if (np01 != 0)
			printf("1分  : %d张\n", np01);
	}
	else {
		printf("输入错误，请重新输入\n");
	}

	return 0;
}