#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student {
	char x[20];
	int f;
	struct student* next;
};
int main() {
	int n;
	printf("需要输入的学生个数：");
	scanf("%d", &n);
	struct student* head;
	struct student* p1, * p2;
	head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	printf("请输入姓名：");
	scanf("%s", p1->x);
	printf("\n请输入成绩：");
	scanf("%d", &p1->f);
	for (int i = 1; i <= n;i++) {
		if (i == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		printf("请输入姓名：");
		scanf("%s", p1->x);
		printf("\n请输入成绩：");
		scanf("%d", &p1->f);
	}
	p2->next = NULL;
	p2 = head;
	if (head != NULL) {
		do {
			printf("%s  :%d", p2->x, p2->f);
			p2 = p2->next;
		} while (p2 != NULL);
	}
	return 0;
}
