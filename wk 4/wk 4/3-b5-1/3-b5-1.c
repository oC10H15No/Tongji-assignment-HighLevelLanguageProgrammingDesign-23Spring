/*2351050 信05 杨瑞晨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, day, n=0;
	printf("请输入年，月，日\n");
	scanf("%d%d%d", &year, &month, &day);

	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {     //年份非闰年
		if (month >= 1 && month <= 12) {                           //月份合法
			if (month == 2) {                                                          //2月
				if (day >= 1 && day <= 28) {                                           //日期合法
					n = day + 31;
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //小月
				if (day >= 1 && day <= 30) {                                           //日期合法
					switch (month) {
						case 4:
							n = day + 31 + 28 + 31;
							break;
						case 6:
							n = day + 31 + 28 + 31 + 30 + 31;
							break;
						case 9:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
							break;
						case 11:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
							break;
						default:
							break;
					}
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
			else {                                                                     //大月
				if (day >= 1 && day <= 31) {                                           //日期合法
					switch (month) {
						case 1:
							n = day;
							break;
						case 3:
							n = day + 31 + 28;
							break;
						case 5:
							n = day + 31 + 28 + 31 + 30;
							break;
						case 7:
							n = day + 31 + 28 + 31 + 30 + 31 + 30;
							break;
						case 8:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
							break;
						case 10:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
							break;
						case 12:
							n = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
							break;
						default:
							break;
					}
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
		}
		else                                                       //月份非法
			printf("输入错误-月份不正确\n");
	}
	else {                                                         //年份是闰年
		if (month >= 1 && month <= 12) {                           //月份合法
			if (month == 2) {                                                          //2月
				if (day >= 1 && day <= 29) {                                           //日期合法
					n = day + 31;
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //小月
				if (day >= 1 && day <= 30) {                                           //日期合法
					switch (month) {
						case 4:
							n = day + 31 + 29 + 31;
							break;
						case 6:
							n = day + 31 + 29 + 31 + 30 + 31;
							break;
						case 9:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
							break;
						case 11:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
							break;
						default:
							break;
					}
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
			else {                                                                     //大月
				if (day >= 1 && day <= 31) {                                           //日期合法
					switch (month) {
						case 1:
							n = day;
							break;
						case 3:
							n = day + 31 + 29;
							break;
						case 5:
							n = day + 31 + 29 + 31 + 30;
							break;
						case 7:
							n = day + 31 + 29 + 31 + 30 + 31 + 30;
							break;
						case 8:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
							break;
						case 10:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
							break;
						case 12:
							n = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
							break;
						default:
							break;
					}
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
				}
				else                                                                   //日期非法
					printf("输入错误-日与月的关系非法\n");
			}
		}
		else                                                       //月份非法
			printf("输入错误-月份不正确\n");
	}

	return 0;
}
