/*���� 2351050 ��05*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������ɼ������1000������������������\n");
	int score[1000];
	for (int i = 0; i < 1000; i++) {
		scanf("%d", &score[i]);
		if (score[i] < 0)
			break;
	}
	
	if (score[0] < 0) {
		printf("����Ч����\n");
		return 0;
	}

	printf("���������Ϊ:\n");
	for (int i = 0; i < 1000; i++) {
		if (score[i] < 0)
			break;
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d ", score[i]);
		
	}
	printf("\n");

	int sum[101] = { 0 };
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j < 1000; j++) {
			if (score[j] == i)
				sum[i]++;
		}
	}
	for (int i = 100; i >= 0; i--) {
		if (sum[i])
			printf("%d %d\n", i, sum[i]);
	}

	return 0;
}