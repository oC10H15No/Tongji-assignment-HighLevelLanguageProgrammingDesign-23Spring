#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n = 0, i, m, k;
    bool prime;
    for (m = 103; m <= 200; m += 2) { //ż��û��Ҫ�ж�
        prime = true;            //��ÿ����������Ϊ������
        k = int(sqrt(m));
        for (i = 2; i <= k; i++)
            if (m % i == 0) {
                prime = false;
                break;
            }

        if (prime) {
            cout << setw(5) << m;
            n = n + 1;      //��������ֻΪ�˼��������
            if (n % 10 == 0)    //ÿ10�������һ��
                cout << endl;
        }
    } //end of for

    return 0;
}
