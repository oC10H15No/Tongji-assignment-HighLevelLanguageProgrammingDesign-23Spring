/* 2351050 ���� ��05 */
#include <iostream>
#include <cstring>
using namespace std;

#define NUM_PERSON 10
#define ID_LEN 8
#define NAME_LEN 9

void input(string ID[], string name[], int grade[])
{
	for (int i = 0; i < NUM_PERSON; i++) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> ID[i];
		cin >> name[i];
		cin >> grade[i];
	}
}

void output(string ID[], string name[], int grade[])
{
	printf("����������(�ɼ�����):\n");
	for (int i = 0; i < NUM_PERSON; i++) {
		if (grade[i] < 60)
			cout << name[i] << " " << ID[i] << " " << grade[i] << endl;
	}
}

void sort(string ID[], string name[], int grade[])
{
	for (int i = 0; i < NUM_PERSON - 1; i++) {
		for (int j = 0; j < NUM_PERSON - 1 - i; j++) {
			string temp_ID;
			string temp_name;
			int temp_grade;
			int diff = (grade[j] > grade[j + 1] ? 1 : 0);
			if (diff > 0) {
				//����ѧ��
				temp_ID = ID[j];
				ID[j] = ID[j + 1];
				ID[j + 1] = temp_ID;
				//��������
				temp_name = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp_name;
				//�����ɼ�
				temp_grade = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = temp_grade;
			}
		}
	}
}

int main()
{
	string ID[NUM_PERSON];
	string name[NUM_PERSON];
	int grade[NUM_PERSON];

	input(ID, name, grade);
	sort(ID, name, grade);
	printf("\n");
	output(ID, name, grade);

	return 0;
}