/*2351050 ��05 ����*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	cout << "������[0-100��)֮�������:" << endl;
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

	cout << "��д�����:" << endl;

	bool zero = 0; //�ж�λ���Ƿ�Ϊ0����Ϊ0��Ϊ�棻��0Ϊ�١�

	//����
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0)
		cout << "��Բ";

	//ʮ��
	if (n1 > 0) {
		switch (n1) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
	}
	//��
	if (n2 > 0) {
		switch (n2) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
	}
	if (n1 > 0 || n2 > 0) {
		cout << "��";
	}

	//ǧ��
	if (n3 == 0) {
		if (n1 > 0 || n2 > 0) {
			zero = 1;
		}
	}
	if (n3 > 0) {
		switch (n3) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "Ǫ";
	}
	//����
	if (n4 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0) {
			zero = 1;
		}
	}
	if (n4 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n4) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	//ʮ��
	if (n5 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0) {
			zero = 1;
		}
	}
	if (n5 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n5) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
	}
	//��
	if (n6 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0) {
			zero = 1;
		}
	}
	if (n6 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n6) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
	}
	if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
		cout << "��";
	}

	zero = 0;

	//ǧ
	if (n7 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
			zero = 1;
		}
	}
	if (n7 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n7) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "Ǫ";
	}
	//��
	if (n8 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0) {
			zero = 1;
		}
	}
	if (n8 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n8) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	//ʮ
	if (n9 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0) {
			zero = 1;
		}
	}
	if (n9 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n9) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
	}
	//��
	if (n10 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0) {
			zero = 1;
		}
	}
	if (n10 > 0) {
		if (zero) {
			cout << "��";
			zero = 0;
		}
		switch (n10) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
	}

	if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
		cout << "Բ";
	}

	if (n11 == 0 && n12 == 0) {
		cout << "��";
	}

	//��
	if (n11 == 0 && n12 != 0 && (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0)) {
		cout << "��";
	}
	if (n11 > 0) {
		switch (n11) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}

	if (n11 != 0 && n12 == 0) {
		cout << "��";
	}

	//��
	if (n12 > 0) {
		switch (n12) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}

	cout << endl;

	return 0;
}