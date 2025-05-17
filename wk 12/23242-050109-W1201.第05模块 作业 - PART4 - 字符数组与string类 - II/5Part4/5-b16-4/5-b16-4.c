/* 2351050 杨瑞晨 信05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_PERSON 10
#define ID_LEN 8
#define NAME_LEN 9

void input(char ID[][ID_LEN], char name[][NAME_LEN], int grade[])
{
	for (int i = 0; i < NUM_PERSON; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", ID[i], name[i], &grade[i]);
	}
}

void output(char ID[][ID_LEN], char name[][NAME_LEN], int grade[])
{
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < NUM_PERSON; i++) {
		printf("%s %s %d\n", name[i], ID[i], grade[i]);
	}
}

void sort(char ID[][ID_LEN], char name[][NAME_LEN], int grade[])
{
	for (int i = 0; i < NUM_PERSON - 1; i++) {
		for (int j = 0; j < NUM_PERSON - 1 - i; j++) {
			char temp_ID[ID_LEN];
			char temp_name[NAME_LEN];
			int temp_grade;
			int diff = (grade[j] < grade[j + 1] ? 1 : 0);
			if (diff > 0) {
				//交换学号
				strcpy(temp_ID, ID[j]);
				strcpy(ID[j], ID[j + 1]);
				strcpy(ID[j + 1], temp_ID);
				//交换姓名
				strcpy(temp_name, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp_name);
				//交换成绩
				temp_grade = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = temp_grade;
			}
		}
	}
}

int main()
{
	char ID[NUM_PERSON][ID_LEN];
	char name[NUM_PERSON][NAME_LEN];
	int grade[NUM_PERSON];

	input(ID, name, grade);
	sort(ID, name, grade);
	printf("\n");
	output(ID, name, grade);

	return 0;
}