/* 2351050 ���� ��05 */

#include "magic_ball.h"

int main()
{
	
	while (1) {
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("������", 18);
		const int select = menu();
		cout << endl;
		if (select == '0')
			return 0;
		magic_ball(select);//���ݲ˵�����ò�ͬ�������

		end();//����end���������ز˵���
	}

	return 0;
}