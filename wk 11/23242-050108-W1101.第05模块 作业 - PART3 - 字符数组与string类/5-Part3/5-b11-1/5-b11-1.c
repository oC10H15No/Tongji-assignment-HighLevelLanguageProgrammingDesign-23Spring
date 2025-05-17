/* 2351050 杨瑞晨 信05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
int daxie(int num, int flag_of_zero, int place)
{
	switch (num) {
		case 0:
			if (flag_of_zero) {//此标记什么意思请自行思考
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	printf("请输入[0-100亿)之间的数字:\n");
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

	printf("大写结果是:\n");
	int place = 0;
	
	char unit[] = "亿万仟佰拾圆角分整";

	int zero = 0; //判断位数是否为0。若为0则为真；非0为假。

	//十亿
	if (n1 > 0) {
		place = daxie(n1, 0, place);
		result[place++] = unit[8];//"拾"
		result[place++] = unit[9]; 
	}
	//亿
	if (n2 > 0) {
		place = daxie(n2, 0, place);
	}
	if (n1 > 0 || n2 > 0) {
		result[place++] = unit[0];//"亿"
		result[place++] = unit[1];
	}
	//千万
	if (n3 > 0) {
		place = daxie(n3, 0, place);
		result[place++] = unit[4];//"仟"
		result[place++] = unit[5];
	}
	else
		zero = 1;
	//百万
	if (n4 > 0) {
		if (n3 == 0) {
			if (n1 > 0 || n2 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n4, 0, place);
		result[place++] = unit[6];//"佰"
		result[place++] = unit[7];
	}
	else
		zero = 1;
	//十万
	if (n5 > 0) {
		if (n4 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n5, 0, place);
		result[place++] = unit[8];//"拾"
		result[place++] = unit[9];
	}
	else
		zero = 1;
	//万
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
		result[place++] = unit[2];//"万"
		result[place++] = unit[3];
	}

	zero = 0;

	//千
	if (n7 > 0) {
		place = daxie(n7, 0, place);
		result[place++] = unit[4];//"仟"
		result[place++] = unit[5];
	}
	else
		zero = 1;
	//百
	if (n8 > 0) {
		if (n7 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n8, 0, place);
		result[place++] = unit[6];//"佰"
		result[place++] = unit[7];
	}
	else
		zero = 1;
	//十
	if (n9 > 0) {
		if (n8 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n9, 0, place);
		result[place++] = unit[8];//"拾"
		result[place++] = unit[9];
	}
	//个
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
		result[place++] = unit[10];//"圆"
		result[place++] = unit[11];
	}

	if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
		result[place++] = unit[10];//"圆"
		result[place++] = unit[11];
	}

	if (n11 == 0 && n12 == 0) {
		result[place++] = unit[16];//"整"
		result[place++] = unit[17];
	}

	zero = 0;

	//角
	if (n11 > 0) {
		place = daxie(n11, 0, place);
		result[place++] = unit[12];//"角"
		result[place++] = unit[13];
	}
	else
		zero = 1;

	if (n11 != 0 && n12 == 0) {
		result[place++] = unit[16];//"整"
		result[place++] = unit[17];
	}

	//分
	if (n12 > 0) {
		if (n11 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
				place = daxie(0, zero, place);
				zero = 0;
			}
		}
		place = daxie(n12, 0, place);
		result[place++] = unit[14];//"分"
		result[place++] = unit[15];
	}

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}