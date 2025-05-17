/* 信05 2351050 杨瑞晨 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：calc_bonus
  功    能：根据利润计算奖金（四舍五入，精确到元）
  输入参数：profit
  返 回 值：
  说    明：只允许用 if-else语句，用switch-case语句则得分为0
***************************************************************************/
int calc_bonus(int profit)
{
    double bonus = 0.0;
    if (profit <= 100000)
        bonus = profit * 0.1;
    else if (profit <= 200000)
        bonus = 100000 * 0.1 + (profit - 100000) * 0.075;
    else if (profit <= 400000)
        bonus = 100000 * 0.1 + 100000 * 0.075 + (profit - 200000) * 0.05;
    else if (profit <= 600000)
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + (profit - 400000) * 0.03;
    else if (profit <= 1000000)
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (profit - 600000) * 0.015;
    else
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (profit - 1000000) * 0.01;

	int round_bonus = (int)(bonus + 0.5);
    return round_bonus;
}

/***************************************************************************
  函数名称：get_business_profit
  功    能：
  输入参数：从键盘读取一个int型正整数，有错误则按错误处理逻辑的规则，给出输出提示后再次读 
  返 回 值：
  说    明：
***************************************************************************/
int get_business_profit()
{
	int profit;
	while (1) {
		cout << "请输入利润" << endl;
		cin >> profit;
		if (cin.fail()) {
			cin.clear();                                               //清空输入缓冲区
			cin.ignore(INT_MAX, '\n');  //忽略错误值
		}
		else if (profit >= 1)
			break;
	}
	return profit;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int profit;

	profit = get_business_profit();

	cout << "应发奖金数 : " << calc_bonus(profit) << endl;

	return 0;
}
