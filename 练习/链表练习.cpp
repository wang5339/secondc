#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)
struct student{
	long num;
	float score;
	struct student *next;
};
int n;
struct student *creat(void){
	struct student *head;
	struct student *p1,*p2;
	head=NULL;
	n=0;
	p1=p2=(struct student* )malloc(LEN);
	scanf("%ld,%f",&p1->num,&p1->score);
//	fflush(stdin);
	//getchar();
	while(p1->num!=0){
		n=n+1;
		if(n==1){
			head=p1;
		}else {
			p2->next=p1;
		}
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%ld,%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	free(p1);
	return(head);
}
void print(struct student*head){
	struct student *p;
	p=head;
	if(head!=NULL){
		do{
			printf("\nnum:%ld\nscore:%5.1lf\n",p->num,p->score);
			p=p->next;
		}while(p!=NULL);}}
int main(){
	struct student *pt;
	pt=creat();
	print(pt);
//	do{
//		printf("\nnum:%ld\nscore:%5.1lf\n",pt->num,pt->score);
//		pt=pt->next;
//	}while(pt!=NULL);
	//printf("\nnum:%ld\nscore:%5.1lf\n",pt->num,pt->score);
	return 0;
}
