#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "������ɼ�[0-100]" << endl;
    cin >> i;
    if (i >= 90 && i <= 100)
        cout << "��" << endl;
    else if (i >= 80 && i <= 90)
        cout << "��" << endl;
    else if (i >= 70 && i < 80)
        cout << "��" << endl;
    else if (i >= 60 && i < 70)
        cout << "����" << endl;
    else if (i >= 0 && i < 60)
        cout << "������" << endl;
    else
        cout << "�������" << endl;
    cout << "�������" << endl;
    return 0;
}
