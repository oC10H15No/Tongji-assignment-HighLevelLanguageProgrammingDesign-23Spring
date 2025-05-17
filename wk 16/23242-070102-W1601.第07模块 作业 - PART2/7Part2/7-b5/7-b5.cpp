/* 2351050 ���� ��05 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int round_1;
	int round_2;

	friend class stu_list;
	
	void set(int no, const char* name, int r1 = 0, int r2 = 0) {
		stu_no = no;
		strncpy(stu_name, name, MAX_NAME_LEN);
		round_1 = r1;
		round_2 = r2;
	}
	int get_no() const {
		return stu_no;
	}
	const char* get_name() const {
		return stu_name;
	}
	int is_round_1() const {
		return round_1;
	}
	int is_round_2() const {
		return round_2;
	}
	void set_round_1(bool status) {
		round_1 = status;
	}

	void set_round_2(bool status) {
		round_2 = status;
	}
	// �������� stu_merge ����
	static void swap(stu_merge& a, stu_merge& b) {
		stu_merge temp = a;
		a = b;
		b = temp;
	}
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void merge();
	void sort();
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::merge()
{
	int index = 0;
	// �ϲ���һ��ѡ������
	for (int i = 0; i < list_num_1; i++) {
		bool found = 0;
		for (int j = 0; j < index; j++) {
			if (list_merge[j].get_no() == list_round_1[i].no) {
				list_merge[j].set_round_1(1);
				found = 1;
				break;
			}
		}
		if (!found) {
			list_merge[index].set(list_round_1[i].no, list_round_1[i].name, 1, 0);
			index++;
		}
	}
	// �ϲ��ڶ���ѡ������
	for (int i = 0; i < list_num_2; i++) {
		bool found = 0;
		for (int j = 0; j < index; j++) {
			if (list_merge[j].get_no() == list_round_2[i].no) {
				list_merge[j].set_round_2(1);
				found = 1;
				break;
			}
		}
		if (!found) {
			list_merge[index].set(list_round_2[i].no, list_round_2[i].name, 0, 1);
			index++;
		}
	}
	list_merge_num = index;
}

void stu_list::sort()
{
	// ����
	for (int i = 0; i < list_merge_num - 1; i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				stu_merge::swap(list_merge[j], list_merge[j + 1]);
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	merge();
	sort();

	if (prompt) 
		cout << prompt << endl;

	cout << "============================================================\n";
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���\n";
	cout << "============================================================\n";

	const char t[][10] = { "��ѡ","�˿�" };

	cout << setiosflags(ios::left);
	for (int i = 0; i < list_merge_num; i++) {
		cout << setw(5) << i + 1;
		cout << setw(9) << list_merge[i].get_no();
		cout << setw(32) << list_merge[i].get_name();
		cout << setw(7) << (list_merge[i].is_round_1() ? "Y" : "/");
		cout << setw(7);
		if (list_merge[i].is_round_1() && list_merge[i].is_round_2())
			cout << "Y";
		else if (list_merge[i].is_round_1() == 1 && list_merge[i].is_round_2() == 0)
			cout << t[1];
		else if (list_merge[i].is_round_1() == 0 && list_merge[i].is_round_2() == 1)
			cout << t[0];
		cout << endl;
	}

	cout << "============================================================\n";
	
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */


	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}
