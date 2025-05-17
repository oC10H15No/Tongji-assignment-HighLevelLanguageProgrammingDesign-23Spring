/*2351050 ÐÅ05 ÑîÈð³¿*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%dx%d=%-4d", j, i, i * j);
		}
	printf("\n");
	}
	printf("\n");
	return 0;
}