/*2351050 信05 杨瑞晨*/
#include <iostream>
#include <cmath> 
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：num flag_of_zero
  返 回 值：void
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> num;

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

	cout << "大写结果是:" << endl;

	int zero = 0; //判断位数是否为0。若为0则为真；非0为假。

	//特判
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0) {
		zero = 1;
		daxie(0, zero);
		cout << "圆";
	}

	//十亿
	if (n1 > 0) {
		daxie(n1, 0);
		cout << "拾";
	}
	//亿
	if (n2 > 0) {
		daxie(n2, 0);
	}
	if (n1 > 0 || n2 > 0) {
		cout << "亿";
	}
	//千万
	if (n3 > 0) {
		daxie(n3, 0);
		cout << "仟";
	}
	else
		zero = 1;
	//百万
	if (n4 > 0) {
		if (n3 == 0) {
			if (n1 > 0 || n2 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n4, 0);
		cout << "佰";
	}
	else
		zero = 1;
	//十万
	if (n5 > 0) {
		if (n4 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n5, 0);
		cout << "拾";
	}
	else
		zero = 1;
	//万
	if (n6 > 0) {
		if (n5 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n6, 0);
	}
	if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
		cout << "万";
	}

	zero = 0;

	//千
	if (n7 > 0) {
		daxie(n7, 0);
		cout << "仟";
	}
	else
		zero = 1;
	//百
	if (n8 > 0) {
		if (n7 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n8, 0);
		cout << "佰";
	}
	else
		zero = 1;
	//十
	if (n9 > 0) {
		if (n8 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n9, 0);
		cout << "拾";
	}
	//个
	if (n10 > 0) {
		if (n9 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n10, 0);
	}

	if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
		cout << "圆";
	}

	if (n11 == 0 && n12 == 0) {
		cout << "整";
	}

	zero = 0;

	//角
	if (n11 > 0) {
		daxie(n11, 0);
		cout << "角";
	}
	else
		zero = 1;

	if (n11 != 0 && n12 == 0) {
		cout << "整";
	}

	//分
	if (n12 > 0) {
		if (n11 == 0) {
			if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
				daxie(0, zero);
				zero = 0;
			}
		}
		daxie(n12, 0);
		cout << "分";
	}

	cout << endl;

	return 0;
}