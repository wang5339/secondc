#include <stdio.h>
typedef struct student{
	char name[40];
	char sex[6];
	int age;
}Stu;
void input(Stu *stu)
{
	for (int i = 0; i < 5; i++)
		scanf("%s %s %d", stu[i].name, stu[i].sex, &stu[i].age);
}
void output(Stu *stu)
{
	for (int i = 0; i < 5; i++)
		printf("%s  %s  %d\n", stu[i].name, stu[i].sex, stu[i].age);
}
int main(void)
{
	Stu stu[5];
	printf("������5��ѧ������Ϣ��\n");
	input(stu);
	printf("\nѧ����Ϣ���£�\n");
	printf("����  �Ա�  ����\n");
	output(stu);
	return 0;
}

