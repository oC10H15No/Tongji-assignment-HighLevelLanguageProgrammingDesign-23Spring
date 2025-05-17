/*杨瑞晨 2351050 信05*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int score[1000];
	for (int i = 0; i < 1000; i++) {
		scanf("%d", &score[i]);
		if (score[i] < 0)
			break;
	}
	
	if (score[0] < 0) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (int i = 0; i < 1000; i++) {
		if (score[i] < 0)
			break;
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d ", score[i]);
		
	}
	printf("\n");

	int sum[101] = { 0 };
	printf("分数与人数的对应关系为:\n");
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