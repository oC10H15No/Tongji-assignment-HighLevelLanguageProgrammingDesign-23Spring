/*���� 2351050 ��05*/
#include <iostream>
#include <iomanip>
using namespace std;

int top[3] = { 0 };
int stack[3][10] = { 0 };

void move(char src, char dst)
{
	int temp = 0;

	if (src == 'A') {
		temp = stack[0][--top[0]];
		stack[0][top[0]] = 0;
	}
	else if (src == 'B') {
		temp = stack[1][--top[1]];
		stack[1][top[1]] = 0;
	}
	else if (src == 'C') {
		temp = stack[2][--top[2]];
		stack[2][top[2]] = 0;
	}

	if (dst == 'A') {
		stack[0][top[0]++] = temp;
	}
	else if (dst == 'B') {
		stack[1][top[1]++] = temp;
	}
	else if (dst == 'C') {
		stack[2][top[2]++] = temp;
	}
}

void printStack()
{
	int i;
	cout << " A:";
	for (i = 0; i < 10; i++) {
		if (stack[0][i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stack[0][i];
	}
	cout << " B:";
	for (i = 0; i < 10; i++) {
		if (stack[1][i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stack[1][i];
	}
	cout << " C:";
	for (i = 0; i < 10; i++) {
		if (stack[2][i] == 0)
			cout << setw(2) << " ";
		else
			cout << setw(2) << stack[2][i];
	}
	cout << endl;
}

void initial(int n, char src, char dst)
{
	int i = n, j = 0;
	for (i = n; i > 0; i--) {
		if (src == 'A')
			stack[0][j] = i;
		else if (src == 'B')
			stack[1][j] = i;
		else if (src == 'C')
			stack[2][j] = i;
		j++;
	}
	if (src == 'A')
		top[0] = j;
	else if (src == 'B')
		top[1] = j;
	else if (src == 'C')
		top[2] = j;
}

void hanoi(int n, char src, char tmp, char dst)
{
	static int count = 0;
	if (n == 1) {
		count++;
		cout << "��" << setiosflags(ios::right) << setw(4) << count << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);
		printStack();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		count++;
		cout << "��" << setiosflags(ios::right) << setw(4) << count << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);
		printStack();
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	char src, dst, tmp;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		if (cin.fail() || n < 1 || n > 10) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (cin.fail() || src < 'A' || src > 'c' || (src > 'C' && src < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (src > 96) {
				src = src - 32;//Сд��ĸת��д
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		if (cin.fail() || dst < 'A' || dst > 'c' || (dst > 'C' && dst < 'a')) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (dst > 96) {
				dst = dst - 32;//Сд��ĸת��д
			}
			if (src == dst) {
				cout << "Ŀ����(" << src << ")" << "��������ʼ��(" << dst << ")��ͬ" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}

	tmp = 3 * 'B' - src - dst;
	initial(n, src, dst);
	cout << "��ʼ:" << setw(15) << " ";
	printStack();
	hanoi(n, src, tmp, dst);

	return 0;
}