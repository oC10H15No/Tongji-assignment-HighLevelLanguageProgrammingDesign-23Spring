/*2351050 ��05 ����*/
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
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d%d%d", &y, &m, &d);

		if (ret != 3) {
			while (getchar() != '\n')
				;
			printf("�����������������\n");
			continue;
		}
		else if (y < 1900 || y > 2100) {
			printf("��ݲ���ȷ������������\n");
			while (getchar() != '\n')
				;
			continue;
		}
		else if (m < 1 || m > 12) {
			printf("�·ݲ���ȷ������������\n");
			while (getchar() != '\n')
				;
			continue;
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d > 31) {
				printf("�ղ���ȷ������������\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d > 30) {
				printf("�ղ���ȷ������������\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		else if (m == 2) {
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
				if (d < 1 || d > 29) {
					printf("�ղ���ȷ������������\n");
					while (getchar() != '\n')
						;
					continue;
				}
			}

			else if (d < 1 || d > 28) {
				printf("�ղ���ȷ������������\n");
				while (getchar() != '\n')
					;
				continue;
			}
		}
		break;
	}

	w = zeller(y, m, d);
	printf("����");
	switch (w) {
		case 0:
			printf("��");
			break;
		case 1:
			printf("һ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
		default:
			break;
	}
	printf("\n");

	return 0;
}