/* 2351050 ���� ��05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			  2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		count++;
		printf("%5d: %2d# %c-->%c\n", count, n, src, dst);
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		count++;
		printf("%5d: %2d# %c-->%c\n", count, n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
	int ret;
	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		ret = scanf("%d", &n);
		if (ret == 0 || n < 1 || n > 16) {
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
		printf("��������ʼ��(A-C)\n");
		ret = scanf("%c", &src);
		if (ret == 0 || src < 'A' || src > 'c' || (src > 'C' && src < 'a')) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (src > 96) {
				src = src - 32;//Сд��ĸת��д
			}
			while (getchar() != '\n')
				;
			break;
		}
	}
	while (1) {
		printf("������Ŀ����(A-C)\n");
		ret = scanf("%c", &dst);
		if (ret == 0 || dst < 'A' || dst > 'c' || (dst > 'C' && dst < 'a')) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (dst > 96) {
				dst = dst - 32;//Сд��ĸת��д
			}
			if (src == dst) {
				printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, dst);
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
	printf("�ƶ�����Ϊ:\n");
	hanoi(n, src, tmp, dst);

	return 0;
}