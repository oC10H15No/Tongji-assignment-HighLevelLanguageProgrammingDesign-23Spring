/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int c, w;

	if (m == 1 || m == 2) {
		m += 12;
		y -= 1;
	}

	c = y / 100;
	y = y % 100;

	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	while (w < 0) {
		w += 7;
	}
	w = w % 7;

	return w;
}

int main()
{
	int y, m, d, w;

	int ret;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d%d%d", &y, &m, &d);

		if (ret != 3) {
			while (getchar() != '\n')
				;
			printf("输入错误，请重新输入\n");
			continue;
		}
		else if (y < 1900 || y > 2100) {
			printf("年份不正确，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		else if (m < 1 || m > 12) {
			printf("月份不正确，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d > 31) {
				printf("日不正确，请重新输入\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d > 30) {
				printf("日不正确，请重新输入\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		else if (m == 2) {
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
				if (d < 1 || d > 29) {
					printf("日不正确，请重新输入\n");
					while (getchar() != '\n')
						;
					continue;
				}
			}

			else if (d < 1 || d > 28) {
				printf("日不正确，请重新输入\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		break;
	}

	w = zeller(y, m, d);
	printf("星期");
	switch (w) {
		case 0:
			printf("日");
			break;
		case 1:
			printf("一");
			break;
		case 2:
			printf("二");
			break;
		case 3:
			printf("三");
			break;
		case 4:
			printf("四");
			break;
		case 5:
			printf("五");
			break;
		case 6:
			printf("六");
			break;
		default:
			break;
	}
	printf("\n");

	return 0;
}