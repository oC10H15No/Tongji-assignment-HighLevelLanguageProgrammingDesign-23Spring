/*ÑîÈð³¿ 2351050 ÐÅ05*/
#include <iostream>
using namespace std;

int main()
{
	int light[101] = { 0 };
	for (int i = 1; i <= 100; i++) {
		int temp = i;
		while (temp <= 100) {
			light[temp] = (light[temp] + 1) % 2;
			temp += i;
		}
	}
	for (int i = 1; i < 100; i++) {
		if (light[i])
			cout << i << " ";
	}
	if (light[100])
		cout << 100 << endl;
	return 0;
}