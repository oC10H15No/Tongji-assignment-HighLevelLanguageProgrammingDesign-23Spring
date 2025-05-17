/* 2351050 杨瑞晨 信05 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名
	

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
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
	// 交换两个 stu_merge 对象
	static void swap(stu_merge& a, stu_merge& b) {
		stu_merge temp = a;
		a = b;
		b = temp;
	}
public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void merge();
	void sort();
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */
void stu_list::merge()
{
	int index = 0;
	// 合并第一轮选课名单
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
	// 合并第二轮选课名单
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
	// 排序
	for (int i = 0; i < list_merge_num - 1; i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				stu_merge::swap(list_merge[j], list_merge[j + 1]);
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	merge();
	sort();

	if (prompt) 
		cout << prompt << endl;

	cout << "============================================================\n";
	cout << "序号 学号     姓名                            第一轮 第二轮\n";
	cout << "============================================================\n";

	const char t[][10] = { "补选","退课" };

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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */


	/* 打印 */
	list.print("最终选课名单");

	return 0;
}
