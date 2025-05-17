/*���� 2351050 ��05*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int notLeapYear(int year)
{
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
		return 1;//��ݷ�����
	else
		return 0;//����
}

int numDay(int year, int month, int day)
{
	int dayNotLeapYear[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int dayLeapYear[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int n = 0;
	if (notLeapYear(year)) {
		for (int i = 0; i < month; i++)
			n += dayNotLeapYear[i];
		n += day;
	}
	else {
		for (int i = 0; i < month; i++)
			n += dayLeapYear[i];
		n += day;
	}
	return n;
}

int main()
{
	int year, month, day, n = 0;
	printf("�������꣬�£���\n");
	scanf("%d%d%d", &year, &month, &day);

	if (notLeapYear(year)) {     
		if (month >= 1 && month <= 12) {                           //�·ݺϷ�
			if (month == 2) {                                                          //2��
				if (day >= 1 && day <= 28) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //С��
				if (day >= 1 && day <= 30) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
			else {                                                                     //����
				if (day >= 1 && day <= 31) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
		}
		else                                                       //�·ݷǷ�
			printf("�������-�·ݲ���ȷ\n");
	}
	else {                                                         //���������
		if (month >= 1 && month <= 12) {                           //�·ݺϷ�
			if (month == 2) {                                                          //2��
				if (day >= 1 && day <= 29) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {          //С��
				if (day >= 1 && day <= 30) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
			else {                                                                     //����
				if (day >= 1 && day <= 31) {                                           //���ںϷ�
					n = numDay(year, month, day);
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, n);
				}
				else                                                                   //���ڷǷ�
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
			}
		}
		else                                                       //�·ݷǷ�
			printf("�������-�·ݲ���ȷ\n");
	}

	return 0;
}
