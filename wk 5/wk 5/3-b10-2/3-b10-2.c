/* 2351050 ��05 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */

	int i, j, k;
	int i1, i2, i3;
	int j1, j2, j3;
	int k1, k2, k3;
	int count = 0;

	for (i = 123; i < 1000; i++) {
		i1 = i / 100 % 10;
		i2 = i / 10 % 10;
		i3 = i % 10;
		if (i1 == 0 || i2 == 0 || i3 == 0)                         //�ж������Ƿ�Ϊ1-9
			continue;
		if (i1 == i2 || i1 == i3 || i2 == i3)                      //�ж������Ƿ��ظ�
			continue;
		for (j = i + 1; j < 1000; j++) {
			j1 = j / 100 % 10;
			j2 = j / 10 % 10;
			j3 = j % 10;
			if (j1 == 0 || j2 == 0 || j3 == 0)                     //�ж������Ƿ�Ϊ1-9
				continue;
			if (j1 == j2 || j1 == j3 || j2 == j3 ||                //�ж������Ƿ��ظ�
				j1 == i1 || j1 == i2 || j1 == i3 ||
				j2 == i1 || j2 == i2 || j2 == i3 ||
				j3 == i1 || j3 == i2 || j3 == i3)
				continue;
			for (k = j + 1; k < 1000; k++) {
				k1 = k / 100 % 10;
				k2 = k / 10 % 10;
				k3 = k % 10;
				if (k1 == 0 || k2 == 0 || k3 == 0)                 //�ж������Ƿ�Ϊ1-9
					continue;
				if (k1 == k2 || k1 == k3 || k2 == k3 ||            //�ж������Ƿ��ظ�
					k1 == i1 || k1 == i2 || k1 == i3 ||
					k2 == i1 || k2 == i2 || k2 == i3 ||
					k3 == i1 || k3 == i2 || k3 == i3 ||
					k1 == j1 || k1 == j2 || k1 == j3 ||
					k2 == j1 || k2 == j2 || k2 == j3 ||
					k3 == j1 || k3 == j2 || k3 == j3)
					continue;
				if (i + j + k == 1953) {
					count++;
					printf("No.%3d : %d+%d+%d=1953\n", count, i, j, k);
				}

			}
		}
	}

	printf("total=%d\n", count);

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}