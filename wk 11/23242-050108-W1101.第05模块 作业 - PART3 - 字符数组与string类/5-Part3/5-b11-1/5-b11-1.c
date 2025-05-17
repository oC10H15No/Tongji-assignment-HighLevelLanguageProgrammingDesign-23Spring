/* 2351050 ���� ��05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
int daxie(int num, int flag_of_zero, int place)
{
	switch (num) {
		case 0:
			if (flag_of_zero) {//�˱��ʲô��˼������˼��
				result[place] = chnstr[num * 2];
				result[place + 1] = chnstr[num * 2 + 1];
				place += 2;
			}
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			result[place] = chnstr[num * 2];
			result[place + 1] = chnstr[num * 2 + 1];
			place += 2;
			break;
		default:
			break;
	}
	return place;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &num);

	num = num + 0.001;
	n1 = (int)(num / 1000000000) % 10;
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	n10 = (int)(fmod(num, 10));
	n11 = (int)(fmod(num, 1) * 10);
	n12 = (int)(fmod(num, 0.1) * 100);

	printf("��д�����:\n");
	int place = 0;
	
	char unit[] = "����Ǫ��ʰԲ�Ƿ���";

	int zero = 0; //�ж�λ���Ƿ�Ϊ0����Ϊ0��Ϊ�棻��0Ϊ�١�

	//ʮ��
	if (n1 > 0) {
		place = daxie(n1, 0, place);
		result[place++] = unit[8];//"ʰ"
		result[place++] = unit[9]; 
	}
	//��
	if (n2 > 0) {
		place = daxie(n2, 0, place);
	}
	if (n1 > 0 || n2 > 0) {
		result[place++] = unit[0];//"��"
		result[place++] = unit[1];
	}
	//ǧ��
	if (n3 > 0) {
		place = daxie(n3, 0, place);
		result[place++] = unit[4];//"Ǫ"
		result[place++] = unit[5];
	}
	else
		zero = 1;
	//����
	if (n4 > 0) {
		if (n3 == 0) {
			if (n1 > 0 || n2 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n4, 0, place);
		result[place++] = unit[6];//"��"
		result[place++] = unit[7];
	}
	else
		zero = 1;
	//ʮ��
	if (n5 > 0) {
		if (n4 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n5, 0, place);
		result[place++] = unit[8];//"ʰ"
		result[place++] = unit[9];
	}
	else
		zero = 1;
	//��
	if (n6 > 0) {
		if (n5 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n6, 0, place);
	}
	if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
		result[place++] = unit[2];//"��"
		result[place++] = unit[3];
	}

	zero = 0;

	//ǧ
	if (n7 > 0) {
		place = daxie(n7, 0, place);
		result[place++] = unit[4];//"Ǫ"
		result[place++] = unit[5];
	}
	else
		zero = 1;
	//��
	if (n8 > 0) {
		if (n7 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n8, 0, place);
		result[place++] = unit[6];//"��"
		result[place++] = unit[7];
	}
	else
		zero = 1;
	//ʮ
	if (n9 > 0) {
		if (n8 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n9, 0, place);
		result[place++] = unit[8];//"ʰ"
		result[place++] = unit[9];
	}
	//��
	if (n10 > 0) {
		if (n9 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n10, 0, place);
	}

	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0) {
		zero = 1;
		place = daxie(0, zero, place);
		result[place++] = unit[10];//"Բ"
		result[place++] = unit[11];
	}

	if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
		result[place++] = unit[10];//"Բ"
		result[place++] = unit[11];
	}

	if (n11 == 0 && n12 == 0) {
		result[place++] = unit[16];//"��"
		result[place++] = unit[17];
	}

	zero = 0;

	//��
	if (n11 > 0) {
		place = daxie(n11, 0, place);
		result[place++] = unit[12];//"��"
		result[place++] = unit[13];
	}
	else
		zero = 1;

	if (n11 != 0 && n12 == 0) {
		result[place++] = unit[16];//"��"
		result[place++] = unit[17];
	}

	//��
	if (n12 > 0) {
		if (n11 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n12, 0, place);
		result[place++] = unit[14];//"��"
		result[place++] = unit[15];
	}

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}