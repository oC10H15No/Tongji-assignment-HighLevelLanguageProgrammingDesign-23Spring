/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, week;

	int ret;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d%d", &year, &month);

		if (ret == 0 || ret == 1) {
			while (getchar() != '\n')                        //清空输入缓冲区
				;
			printf("输入非法，请重新输入\n");
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			printf("输入非法，请重新输入\n");
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret = scanf("%d", &week);

		if (ret == 0) {
			while (getchar() != '\n')                        //清空输入缓冲区
				;
			printf("输入非法，请重新输入\n");
		}
		else if (week >= 0 && week <= 6)
			break;
		else
			printf("输入非法，请重新输入\n");
	}

	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);

	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

	int days;
	int line = 0;

	if (month == 2) {
		if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)      //不是闰年
			days = 28;
		else
			days = 29;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)   //小月
		days = 30;
	else                                                              //大月
		days = 31;

	char space = ' ';
	switch (week) {
		case 0:
			break;
		case 1:
			printf("%8c", space);
			break;
		case 2:
			printf("%16c", space);
			break;
		case 3:
			printf("%24c", space);
			break;
		case 4:
			printf("%32c", space);
			break;
		case 5:
			printf("%40c", space);
			break;
		case 6:
			printf("%48c", space);
			break;
		default:
			break;
	}

	for (int i = 1; i <= days; i++)
		if (1) {
			printf("%4d%4c", i, space);
			line++;
			if ((week + line) % 7 == 0) {
				printf("\n");
			}
		}

	printf("\n");

	return 0;
}