/* 2351050 杨瑞晨 信05 */

#include "magic_ball.h"

int main()
{
	
	while (1) {
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("新宋体", 18);
		const int select = menu();
		cout << endl;
		if (select == '0')
			return 0;
		magic_ball(select);//根据菜单项调用不同函数组合

		end();//输入end结束并返回菜单键
	}

	return 0;
}