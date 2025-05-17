/* 2351050 杨瑞晨 信05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int topA = 0, topB = 0, topC = 0;
int stackA[10] = {0}, stackB[10] = {0}, stackC[10] = {0};
int count = 0;

void move(char src, char dst)
{
	int temp = 0;

	if (src == 'A') {
		temp = stackA[--topA];
		stackA[topA] = 0;
	}
	else if (src == 'B') {
		temp = stackB[--topB];
		stackB[topB] = 0;
	}
	else if (src == 'C') {
		temp = stackC[--topC];
		stackC[topC] = 0;
	}

	if (dst == 'A') {
		stackA[topA++] = temp;
	}
	else if (dst == 'B') {
		stackB[topB++] = temp;
	}
	else if (dst == 'C') {
		stackC[topC++] = temp;
	}
}

void printStack()
{
	int i;
	printf(" A:");
	for (i = 0; i < 10; i++) {
		if (stackA[i] == 0)
			printf("  ");
		else
			printf("%2d", stackA[i]);
	}
	printf(" B:");
	for (i = 0; i < 10; i++) {
		if (stackB[i] == 0)
			printf("  ");
		else
			printf("%2d", stackB[i]);
	}
	printf(" C:");
	for (i = 0; i < 10; i++) {
		if (stackC[i] == 0)
			printf("  ");
		else
			printf("%2d", stackC[i]);
	}
	printf("\n");
}

void initial(int n, char src, char dst)
{
	int i = n, j = 0;
	for (i = n; i > 0; i--) {
		if (src == 'A')
			stackA[j] = i;
		else if (src == 'B')
			stackB[j] = i;
		else if (src == 'C')
			stackC[j] = i;
		j++;
	}
	if (src == 'A')
		topA = j;
	else if (src == 'B')
		topB = j;
	else if (src == 'C')
		topC = j;
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		count++;
		printf("第%4d 步(%2d): %c-->%c", count, n, src, dst);
		move(src, dst);
		printStack();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		count++;
		printf("第%4d 步(%2d): %c-->%c", count, n, src, dst);
		move(src, dst);
		printStack();
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	char src, dst, tmp;
	int ret;
	while (1) {
		printf("请输入汉诺塔的层数(1-10)\n");
		ret = scanf("%d", &n);
		if (ret == 0 || n < 1 || n > 10) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			while (getchar() != '\n')
				;
			break;
		}
	}
	while (1) {
		printf("请输入起始柱(A-C)\n");
		ret = scanf("%c", &src);
		if (ret == 0 || src < 'A' || src > 'c' || (src > 'C' && src < 'a')) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (src > 96) {
				src = src - 32;//小写字母转大写
			}
			while (getchar() != '\n')
				;
			break;
		}
	}
	while (1) {
		printf("请输入目标柱(A-C)\n");
		ret = scanf("%c", &dst);
		if (ret == 0 || dst < 'A' || dst > 'c' || (dst > 'C' && dst < 'a')) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (dst > 96) {
				dst = dst - 32;//小写字母转大写
			}
			if (src == dst) {
				printf("目标柱(%c)不能与起始柱(%c)相同\n", src, dst);
				while (getchar() != '\n')
					;
				continue;
			}
			while (getchar() != '\n')
				;
			break;
		}
	}

	tmp = 3 * 'B' - src - dst;
	initial(n, src, dst);
	char space = ' ';
	printf("初始:%15c",space);
	printStack();
	hanoi(n, src, tmp, dst);

	return 0;
}