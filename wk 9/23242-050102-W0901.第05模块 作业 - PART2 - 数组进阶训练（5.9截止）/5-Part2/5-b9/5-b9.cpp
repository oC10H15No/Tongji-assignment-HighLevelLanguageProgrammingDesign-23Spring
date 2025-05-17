/*2351050 ���� ��05*/
#include <iostream>
using namespace std;

void clear(bool check[]) {
	for (int i = 0; i < 10; i++) { 
		check[i] = 0;
	}
}

bool isValid(bool check[]) { 
	for (int i = 1; i <= 9; i++) { 
		if (!check[i])
			return 0;
	}
	return 1;
}

int main() {
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int sudoku[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) { 
				cin >> sudoku[i][j];
				if (cin.fail()) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl; 
				}
				else if (sudoku[i][j] < 1 || sudoku[i][j] > 9) {
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl; 
				}
				else
					break;
			}
		}
	}

	bool row[10] = { 0 };
	bool col[10] = { 0 };
	bool box[10] = { 0 };

	bool isSudoku = 1;

	//�ж���
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			row[sudoku[i][j]] = 1; 
		}
		if (!isValid(row)) 
			isSudoku = 0; 
		clear(row);
	}

	//�ж���
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			col[sudoku[j][i]] = 1;
		}
		if (!isValid(col)) 
			isSudoku = 0; 
		clear(col);
	}

	//�ж�3*3����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) { 
				for (int l = 0; l < 3; l++) { 
					box[sudoku[i * 3 + k][j * 3 + l]] = 1; 
				}
			}
			if (!isValid(box))
				isSudoku = 0;
			clear(box);
		}
	}

	if (isSudoku)
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;

	return 0;
}