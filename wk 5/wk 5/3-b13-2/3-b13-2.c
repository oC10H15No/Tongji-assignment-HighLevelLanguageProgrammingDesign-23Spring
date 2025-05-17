/*2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, week;

	int ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d%d", &year, &month);

		if (ret == 0 || ret == 1) {
			while (getchar() != '\n')                        //������뻺����
				;
			printf("����Ƿ�������������\n");
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			printf("����Ƿ�������������\n");
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
		ret = scanf("%d", &week);

		if (ret == 0) {
			while (getchar() != '\n')                        //������뻺����
				;
			printf("����Ƿ�������������\n");
		}
		else if (week >= 0 && week <= 6)
			break;
		else
			printf("����Ƿ�������������\n");
	}

	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", year, month);

	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	int days;
	int line = 0;

	if (month == 2) {
		if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)      //��������
			days = 28;
		else
			days = 29;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)   //С��
		days = 30;
	else                                                              //����
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