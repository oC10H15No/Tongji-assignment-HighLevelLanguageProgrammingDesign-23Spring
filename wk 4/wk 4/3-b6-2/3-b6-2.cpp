/*2351050 ÐÅ05 ÑîÈð³¿*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
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

	cout << "´óÐ´½á¹ûÊÇ:" << endl;

	bool zero = 0; //ÅÐ¶ÏÎ»ÊýÊÇ·ñÎª0¡£ÈôÎª0ÔòÎªÕæ£»·Ç0Îª¼Ù¡£

	//ÌØÅÐ
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0)
		cout << "ÁãÔ²";

	//Ê®ÒÚ
	if (n1 > 0) {
		switch (n1) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
	}
	//ÒÚ
	if (n2 > 0) {
		switch (n2) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}
	if (n1 > 0 || n2 > 0) {
		cout << "ÒÚ";
	}

	//Ç§Íò
	if (n3 == 0) {
		if (n1 > 0 || n2 > 0) {
			zero = 1;
		}
	}
	if (n3 > 0) {
		switch (n3) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Çª";
	}
	//°ÙÍò
	if (n4 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0) {
			zero = 1;
		}
	}
	if (n4 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n4) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "°Û";
	}
	//Ê®Íò
	if (n5 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0) {
			zero = 1;
		}
	}
	if (n5 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n5) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
	}
	//Íò
	if (n6 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0) {
			zero = 1;
		}
	}
	if (n6 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n6) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}
	if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
		cout << "Íò";
	}

	zero = 0;

	//Ç§
	if (n7 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) {
			zero = 1;
		}
	}
	if (n7 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n7) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Çª";
	}
	//°Ù
	if (n8 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0) {
			zero = 1;
		}
	}
	if (n8 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n8) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "°Û";
	}
	//Ê®
	if (n9 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0) {
			zero = 1;
		}
	}
	if (n9 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n9) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
	}
	//¸ö
	if (n10 == 0) {
		if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0) {
			zero = 1;
		}
	}
	if (n10 > 0) {
		if (zero) {
			cout << "Áã";
			zero = 0;
		}
		switch (n10) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}

	if (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) {
		cout << "Ô²";
	}

	if (n11 == 0 && n12 == 0) {
		cout << "Õû";
	}

	//½Ç
	if (n11 == 0 && n12 != 0 && (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0)) {
		cout << "Áã";
	}
	if (n11 > 0) {
		switch (n11) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "½Ç";
	}

	if (n11 != 0 && n12 == 0) {
		cout << "Õû";
	}

	//·Ö
	if (n12 > 0) {
		switch (n12) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èþ";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "·Ö";
	}

	cout << endl;

	return 0;
}