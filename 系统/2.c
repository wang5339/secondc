#include<string.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct yaopin)
#define FMT "\t\t\tҩƷ��ţ�%-3d��ҩƷ���ƣ�%-12s�����ۣ�%-6.2fԪ���ۼۣ�%-6.2fԪ���������ڣ�%-15s�������ڣ�%-15s����棺%-4d���������ͣ�%-5s\n"

FILE *fp;

struct Users{
	char name[20];
	char code[10];
}user1;

typedef struct yaopin
{
	int bianhao;
	char mingzi[100];
	float jinjia;
	float danjia;
	char shengchanriqi[100];
	char baozhiqi[100];
	int kucun;
	char chufangleixing[100];
	struct yaopin *next;
};

struct yaopin *creatNode()
{
	struct yaopin *head;
	struct yaopin *p1;
	struct yaopin *p2;
	head=NULL;
	p1=(struct yaopin *)malloc(LEN);
	p2=(struct yaopin *)malloc(LEN);
	int n=0;
	char choice;
	while(1)
	{
		printf("\t\t\t�Ƿ����ҩƷ��Y/N����");
		rewind(stdin);
		scanf("%c",&choice);
		if(choice=='N')
		{
			break;
		}
		printf("\t\t\t����ҩƷ��ţ�");
		scanf("%d",&p1->bianhao); 
		printf("\t\t\t����ҩƷ���ƣ�");
		scanf("%s",&p1->mingzi);
		printf("\t\t\t����ҩƷ���ۣ�");
		scanf("%d",&p1->jinjia); 
		printf("\t\t\t����ҩƷ���ۣ�");
		scanf("%f",&p1->danjia);
		printf("\t\t\t����ҩƷ�������ڣ�");
		scanf("%s",&p1->shengchanriqi);
		printf("\t\t\t����ҩƷ�����ڣ�");
		scanf("%s",&p1->baozhiqi);
		printf("\t\t\t����ҩƷ��棺");
		scanf("%d",&p1->kucun);
		printf("\t\t\t����ҩƷ�������ͣ�");
		scanf("%s",&p1->chufangleixing);
		n++;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct yaopin *)malloc(LEN);	
	}
	p2->next=NULL;
	return(head);
}

void output(struct yaopin *head)
{
	struct yaopin *p;
	if(head!=NULL)
	{
		p=head;
		while(p!=NULL)
		{
			if(p->danjia==0.00){
				printf("\t\t\tδ������ϵͳ��ҩƷ��Ϣ��\n");
				break;
			}
			printf(FMT,p->bianhao,p->mingzi,p->jinjia,p->danjia,p->shengchanriqi,p->baozhiqi,p->kucun,p->chufangleixing);
			p=p->next;
		}
	}
}

void shuru(struct yaopin *head)
{
	struct yaopin *yao;
	yao=head;
	FILE *fp;
	fp=fopen("ҩƷ��Ϣ.txt","wt");
	if((fp=fopen("ҩƷ��Ϣ.txt","wt"))==NULL)
	{
		printf("\t\t\t�޷����ļ�");
		getch();
		exit(0);
	}
	for(yao=head;yao!=NULL;yao=yao->next)
	{
		fprintf(fp,"%d %s %.2f %.2f %s %s %d %s\n",yao->bianhao,yao->mingzi,yao->jinjia,yao->danjia,yao->shengchanriqi,yao->baozhiqi,yao->kucun,yao->chufangleixing );
	}
	fclose(fp);
}

struct yaopin *shuchu()
{
	struct yaopin *ahead,*r,*yao;
	FILE*f1,*f2;
	char ch;
	f1=fopen("ҩƷ��Ϣ.txt","r");
	f2=fopen("ҩƷ��Ϣ.txt","r");
	ahead=(struct yaopin*)malloc(sizeof(struct yaopin));
	ahead->next=NULL;
	r=ahead;
	ch=fgetc(f2);
	if(ch==EOF){
		return NULL;
	}
	while(!feof(f1))
	{
		yao=(struct yaopin*)malloc(sizeof(struct yaopin));
		fscanf(f1,"%d %s %f %f %s %s %d %s\n",&yao->bianhao,&yao->mingzi,&yao->jinjia,&yao->danjia,&yao->shengchanriqi,&yao->baozhiqi,&yao->kucun,&yao->chufangleixing);
		r->next =yao;
		r=yao;
	}
	r->next =NULL;
	fclose(f1);
	return ahead;
}

void shanchu()
{
	struct yaopin *h,*t,*p;
	h=shuchu();
	int j,flag=0,ch;
	char choice,name[10];
	printf("\t\t��ѡ���ѯ��ʽ��\n");
	printf("\t\t\t1 ��ҩƷ��Ų�ѯ\n");
	printf("\t\t\t2 ��ҩƷ���Ʋ�ѯ\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("\t\t\t��������Ҫɾ����ҩƷ��ţ�");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->next->bianhao==j)
				{
					printf("ҩƷ��Ϣ���£�\n"); 
					printf(FMT,t->next->bianhao,t->next->mingzi,t->next->jinjia,t->next->danjia,t->next->shengchanriqi,t->next->baozhiqi,t->next->kucun,t->next->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\tȷ��ɾ����ҩƷ�𣿣�Y/N����");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							printf("\t\t\tɾ��ʧ�ܣ�\n"); 
							break;
						}
						else
						{
							t->next=t->next->next;
							printf("\t\t\tɾ���ɹ���\n");
							break; 
						}
					} 
					break;
				} 
			}
			if(flag==0)
			{
				printf("\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			p=h->next;
			shuru(p);
			output(p);
			break;
		case 2:
			printf("\t\t\t��������Ҫɾ����ҩƷ���֣�");
			scanf("%s",name); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(strcmp(t->mingzi,name)==0);
				{
					printf("ҩƷ��Ϣ���£�\n"); 
					printf(FMT,t->next->bianhao,t->next->mingzi,t->next->jinjia,t->next->danjia,t->next->shengchanriqi,t->next->baozhiqi,t->next->kucun,t->next->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\tȷ��ɾ����ҩƷ�𣿣�Y/N����");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							printf("\t\t\tɾ��ʧ�ܣ�\n"); 
							break;
						}
						else
						{
							t->next=t->next->next;
							printf("\t\t\tɾ���ɹ���\n");
							break; 
						}
					} 
					break;
				} 
			}
			if(flag==0)
			{
				printf("\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			p=h->next;
			shuru(p);
			output(p);
	}
}

void chaxun()
{
	struct yaopin *h,*t;
	h=shuchu();
	int ch;
	printf("\t\t\t��ѡ���ѯ��ʽ��\n");
	printf("\t\t\t\t1 ��ҩƷ��Ų�ѯ\n");
	printf("\t\t\t\t2 ��ҩƷ���Ʋ�ѯ\n");
	printf("\t\t\t\t3 ��ҩƷ�������ͼ��۸������ѯ\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			system("CLS");
			int j,flag=0;
			printf("\t\t\t\t������ҩƷ��ţ�");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->bianhao ==j)
				{
					printf("\t\t\tҩƷ��Ϣ���£�\n");
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			break;
		case 2:
			system("CLS");
			char name[10];
			flag=0;
			printf("\t\t\t\t������ҩƷ���ƣ�");
			scanf("%s",name);
			for(t=h;t!=NULL;t=t->next){
				if(strcmp(name,t->mingzi)==0){
					printf("\t\t\tҩƷ��Ϣ���£�\n"); 
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			break;
		case 3:
			system("CLS");
			float max,min;
			char cf[10];
			flag=0;
			printf("\t\t\t\t�����봦�����ͣ�\n");
			scanf("%s",cf);
			printf("\t\t\t\t������۸�����(����ʱ��С����м��ÿո����)��");
			scanf("%f%f",&min,&max);
			for(t=h;t!=NULL;t=t->next){
				if(t->danjia>=min && t->danjia<=max && strcmp(cf,t->chufangleixing)==0){
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			break;					
	}
}

void xiugai()
{
	struct yaopin *h,*t,*p;
	int ch,j,flag=0;
	char choice;
	char name[20];
	h=shuchu();
	printf("\t\t\t��ѡ���ѯ��ʽ��\n");
	printf("\t\t\t\t1 ��ҩƷ��Ų�ѯ\n");
	printf("\t\t\t\t2 ��ҩƷ���Ʋ�ѯ\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("\t\t\t������ҩƷ��ţ�");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->bianhao ==j)
				{
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\tȷ���޸�ҩƷ��Ϣ�𣿣�Y/N����");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							break;
						}
						else
						{
							printf("\t\t\t����������ҩƷ��ţ�");
							scanf("%d",&t->bianhao);
							printf("\t\t\t����������ҩƷ����");
							scanf("%s",&t->mingzi);
							printf("\t\t\t����������ҩƷ���ۣ�");
							scanf("%f",&t->jinjia);
							printf("\t\t\t���������뵥�ۣ�") ;
							scanf("%f",&t->danjia );
							printf("�����������������ڣ�");
							scanf("%s",&t->shengchanriqi);
							printf("���������뱣���ڣ�");
							scanf("%s",&t->baozhiqi);
							printf("\t\t\t�����������棺");
							scanf("%d",&t->kucun );
							printf("\t\t\t���������봦�����ͣ�");
							scanf("%s",&t->chufangleixing);
							printf("\t\t\t�޸�������£�\n");
							printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
						}
					}
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			p=h->next ;
			shuru(p);
			break;
		case 2:
			printf("\t\t\t������ҩƷ���ƣ�");
			scanf("%s",name); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(strcmp(t->mingzi,name)==0)
				{
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\tȷ���޸�ҩƷ��Ϣ�𣿣�Y/N����");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							break;
						}
						else
						{
							printf("\t\t\t����������ҩƷ��ţ�");
							scanf("%d",&t->bianhao);
							printf("\t\t\t����������ҩƷ����");
							scanf("%s",&t->mingzi);
							printf("\t\t\t����������ҩƷ���ۣ�");
							scanf("%f",&t->jinjia);
							printf("\t\t\t���������뵥�ۣ�") ;
							scanf("%f",&t->danjia );
							printf("�����������������ڣ�");
							scanf("%s",&t->shengchanriqi);
							printf("���������뱣���ڣ�");
							scanf("%s",&t->baozhiqi);
							printf("\t\t\t�����������棺");
							scanf("%d",&t->kucun );
							printf("\t\t\t���������봦�����ͣ�");
							scanf("%s",&t->chufangleixing);
							printf("\t\t\t�޸�������£�\n");
							printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
						}
					}
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\tδ���ҵ�ҩƷ��Ϣ��"); 
			}
			p=h->next ;
			shuru(p);
			break;
	}
}

void tongji()
{
	struct yaopin *h,*t;
	h=shuchu();
	char n[10]={"����"};
	int i=0,j=0,m,ch;
	int c=0,d=0;
	printf("��ѡ��ͳ����Ŀ��\n");
	printf("\t\t1 ͳ�Ʋ�ͬ��������ҩ������\n");
	printf("\t\t2 ��������ѹ��ѹ���\n");
	printf("\t\t3 ������治�����\n");
	scanf("%d",&ch); 
	switch(ch){
		case 1:
			system("CLS");
			for(t=h->next ;t!=NULL;t=t->next)
			{
				m=strcmp(t->chufangleixing,n);
				if(m==0)
				{
					i++;
				}
				else
				{
					j++;
				}
			}
			printf("\t\tͳ�ƽ����\n");
			printf("\t\t\t������ҩ��%d�֣��Ǵ�����ҩ��%d�֡�\n",i,j);
			break;
		case 2:
			system("CLS");
			for(t=h->next;t!=NULL;t=t->next){
				if(t->kucun>=100){
					printf("\t\t\t%s, ҩƷ���Ϊ%d��ҩƷ���Ϊ%d\n",t->mingzi,t->bianhao,t->kucun);
					c++;
				}
			}
			if(c==0){
				printf("\t\t\t��ҩƷ����ѹ�����\n"); 
			}
			else{
				printf("\t\t\t����ҩƷ���������100��������ɿ���ѹ����Ҫ���ٽ�����\n"); 
			}
			break; 
		case 3:
			system("CLS");
			for(t=h->next;t!=NULL;t=t->next){
				if(t->kucun<=20){
					printf("\t\t\t%s, ҩƷ���Ϊ%d��ҩƷ���Ϊ%d\n",t->mingzi,t->bianhao,t->kucun);
					d++;
				}
			}
			if(d==0){
				printf("\t\t\t��ҩƷ��治�������\n"); 
			}
			else{
				printf("\t\t\t����ҩƷ�����С��20�����뼰ʱ������\n"); 
			}
			break;
	}
}

void paixu()
{
	struct yaopin *p,*q,*h,*t;
	h=shuchu();
	int tbianhao;
	char tmingzi[50];
	float tjinjia;
	float tdanjia;
	char tshengchanriqi[50];
	char tbaozhiqi[50];
	int tkucun;
	char tchufangleixing[50];
	int ch;
	printf("\t\t��ѡ��\n"); 
	printf("\t\t\t1 ҩƷ�����������\n\t\t\t2 ҩƷ����������\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			for(p=h->next;p->next!=NULL;p=p->next)
			{
				for(q=p->next;q!=NULL;q=q->next)
				{
					if(p->kucun > q->kucun)
					{
						tbianhao=p->bianhao;
					    p->bianhao=q->bianhao;
					    q->bianhao=tbianhao;
					    
						strcpy(tmingzi,p->mingzi);
					    strcpy(p->mingzi,q->mingzi);
					    strcpy(q->mingzi,tmingzi);
					    
					    tjinjia=p->jinjia;
					    p->jinjia=q->jinjia;
					    q->jinjia=tjinjia;
					
					    tdanjia=p->danjia;
					    p->danjia=q->danjia;
					    q->danjia=tdanjia;
					    
					    strcpy(tshengchanriqi,p->shengchanriqi);
					    strcpy(p->shengchanriqi,q->shengchanriqi);
					    strcpy(q->shengchanriqi,tshengchanriqi);
					    
					    strcpy(tbaozhiqi,p->baozhiqi);
					    strcpy(p->baozhiqi,q->baozhiqi);
					    strcpy(q->baozhiqi,tbaozhiqi);
					
					    tkucun=p->kucun;
					    p->kucun=q->kucun;
					    q->kucun=tkucun;
					
					    strcpy(tchufangleixing,p->chufangleixing);
					    strcpy(p->chufangleixing,q->chufangleixing);
					    strcpy(q->chufangleixing,tchufangleixing);
					}
				}
			}
			printf("\t\t��ҩƷ��潫ҩƷ�����������£�\n");
			for(t=h->next;t!=NULL;t=t->next)
			{
				printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
			}
			break;
		case 2:
			for(p=h->next;p->next!=NULL;p=p->next)
			{
				for(q=p->next;q!=NULL;q=q->next)
				{
					if((p->danjia - p->jinjia) < (q->danjia - q->jinjia))
					{
						tbianhao=p->bianhao;
					    p->bianhao=q->bianhao;
					    q->bianhao=tbianhao;
					    
						strcpy(tmingzi,p->mingzi);
					    strcpy(p->mingzi,q->mingzi);
					    strcpy(q->mingzi,tmingzi);
					    
					    tjinjia=p->jinjia;
					    p->jinjia=q->jinjia;
					    q->jinjia=tjinjia;
					
					    tdanjia=p->danjia;
					    p->danjia=q->danjia;
					    q->danjia=tdanjia;
					    
					    strcpy(tshengchanriqi,p->shengchanriqi);
					    strcpy(p->shengchanriqi,q->shengchanriqi);
					    strcpy(q->shengchanriqi,tshengchanriqi);
					    
					    strcpy(tbaozhiqi,p->baozhiqi);
					    strcpy(p->baozhiqi,q->baozhiqi);
					    strcpy(q->baozhiqi,tbaozhiqi);
					
					    tkucun=p->kucun;
					    p->kucun=q->kucun;
					    q->kucun=tkucun;
					
					    strcpy(tchufangleixing,p->chufangleixing);
					    strcpy(p->chufangleixing,q->chufangleixing);
					    strcpy(q->chufangleixing,tchufangleixing);
					}
				}
			}
			printf("\t\t��ҩƷ����ҩƷ�����������£�\n");
			for(t=h->next;t!=NULL;t=t->next)
			{
				printf("\t\t\tҩƷ��ţ�%-3d��ҩƷ���ƣ�%-12s������%-6.2fԪ���������ڣ�%-15s�������ڣ�%-15s����棺%-4d���������ͣ�%-5s\n",t->bianhao,t->mingzi,(t->danjia - t->jinjia),t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
			}
			break;	
	}	
} 

void baobiao()
{
	struct yaopin *h,*t;
	h=shuchu();
	printf("\t��ҩƷͳ�ƺ����ɱ�������:\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t| **%15s%15s%15s%15s%15s%19s%19s%15s  ** |\n","ҩƷ���","ҩƷ����","ҩƷ����","ҩƷ����","��������","������","ҩƷ���","��������");
	for(t=h->next;t!=NULL;t=t->next)
	{
		printf("\t\t\t| **%15d%15s%15.2f%15.2f%19s%19s%15d%15s  ** |\n",t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
	}
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void tianjia()
{
	struct yaopin *p,*head,*t;
	char n;
	int num,k=-1;
	head=shuchu();
	output(head->next);
	printf("\t\t\t���������ҩƷ�Ĵ���");
	scanf("%d",&num);
	for(p=head;p!=NULL;p=p->next){
		k++;
		if(k==num-1){
			t=(struct yaopin *)malloc(LEN);
			printf("\t\t\t����ҩƷ��ţ�");
		    scanf("%d",&t->bianhao);
		    printf("\t\t\t����ҩƷ���ƣ�");
			scanf("%s",&t->mingzi);
			printf("\t\t\t����ҩƷ���ۣ�");
			scanf("%f",&t->jinjia);
	        printf("\t\t\t����ҩƷ���ۣ�");
		    scanf("%f",&t->danjia);
		    printf("\t\t\t����ҩƷ�������ڣ�");
		    scanf("%s",&t->shengchanriqi);
		    printf("\t\t\t����ҩƷ�����ڣ�");
		    scanf("%s",&t->baozhiqi);
		    printf("\t\t\t����ҩƷ��棺");
		    scanf("%d",&t->kucun);
		    printf("\t\t\t����ҩƷ�������ͣ�");
		    scanf("%s",&t->chufangleixing);
		    t->next=p->next;
			p->next=t;
			break; 
		}
	}
	printf("\t\t\t��ӳɹ���\n"); 
	shuru(head->next);
	output(head->next); 
}

int caidan() 
{
	char n;
	do
	{
		system("CLS");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t***********��ӭ����ҩ�����ϵͳ**************\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 �鿴ϵͳ��ҩƷ��Ϣ                   ||\n");
		printf("\t\t\t\t||  2 �¼�ָ��ҩƷ��Ϣ                     ||\n");
		printf("\t\t\t\t||  3 ��ѯָ��ҩƷ��Ϣ                     ||\n");
		printf("\t\t\t\t||  4 �޸�ָ��ҩƷ��Ϣ                     ||\n");
		printf("\t\t\t\t||  5 ���ҩƷ                             ||\n");
		printf("\t\t\t\t||  6 ҩƷ�������������                   ||\n");
		printf("\t\t\t\t||  7 ��ӡ����                             ||\n");
		printf("\t\t\t\t||  8 ��ʼ��ϵͳ                           ||\n");
		printf("\t\t\t\t||  9 ͳ��ϵͳ                             ||\n");
		printf("\t\t\t\t||  0 �˳�                                 ||\n"); 
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t��ѡ��1~9��");
		n=getch();
	}while(n<'0'||n>'9');
	return (n-48);
}

void zhuce()
{
	char meg[20],filename[20];
	while(1){
		printf("\n\n\n\n\n\n\n\t\t\t\t�û�ע�᣺\n");
		printf("\t\t\t\t\t�������û�����");
		scanf("%s",user1.name);
		strcat(user1.name,".txt");
		fp=fopen(user1.name,"r+");
		if(fp!=NULL){
			printf("\n\t\t\t\t\t���û��Ѵ��ڣ�\n");
			fclose(fp);
			denglu();
			break;
		}
		printf("\t\t\t\t\t���������룺");
		yincode(user1.code);
		printf("\n\t\t\t\t\tȷ�����룺");
		yincode(meg);
		while(strcmp(user1.code,meg)!=0){
			printf("\n\t\t\t\t\t���벻һ�£����������룺\n");
			printf("\t\t\t\t\t���������룺");
			yincode(user1.code);
			printf("\n\t\t\t\t\tȷ�����룺");
			yincode(meg);
		}
		fp=fopen(user1.name,"wt");
		if(fp==NULL){
			printf("\n\t\t\t\t\tע��ʧ�ܣ�\n");
			exit(0);
		}
		else{
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\tע��ɹ���\n");
			fprintf(fp,"%s",user1.code);	
			fclose(fp);
			sleep(1); 
			system("cls");
			denglujiemian();
			break; 
		}
	}
	fclose(fp);
}

void flwrite()
{
	if(fwrite(&user1,sizeof(struct Users),1,fp)!=1)
    {
        printf("\n\t\tд���ļ�����");
        exit(0);
    }
}

void denglu()
{
	char megn[20],megc[10];
	char n;
	int m=2;
	printf("\t\t\t\t�û���¼��\n");
	printf("\t\t\t\t\t�������û�����");
	scanf("%s",megn);
	strcat(megn,".txt");
	fp=fopen(megn,"r");
	if(fp==NULL){
		printf("\t\t\t\t\t�û������ڣ���ע��\n");
		printf("\t\t\t\t\t1 ע��\n\t\t\t\t\t2 ���µ�½\n\t\t\t\t\t3 �˳�");
		n=getch();
		if(n=='1'){
			system("CLS");
			zhuce();
		} 
		else if(n=='2'){
			system("CLS");
			denglu();
		}
		else{
			exit(0);
		}
	}
	do{
		printf("\t\t\t\t\t������6λ���룺");
		yincode(megc);
		fscanf(fp,"%s",user1.code);
		if(strcmp(user1.code,megc)!=0){
			printf("\n\t\t\t\t\t�������\n");
			printf("\t\t\t\t\t1 �˳�\n\t\t\t\t\t2 �������루��ʣ%d�λ��ᣡ��\n",m);
			fflush(stdin);
			n=getch();
			if(n=='1' || m==0){
				fclose(fp);
				exit(0);
			}
			m--;
		}
		else{
			break;
		}
	}while(n=='2');
}

void yincode(char megc[])
{
	int i;
	while ( i < 50 ){
		megc[i] = getch();
		if (megc[i] == '\r'){
			break;	
		} 
		else if (megc[i] == '\b') { 
			i=i-1; 
			printf("\b \b");
		} 
		else {
			i=i+1;
			printf("*");
		}
	}
	megc[i]='\0';
}

void denglujiemian()
{
	char n;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t��ӭ����ҩ�����ϵͳ1.0��\n");
	printf("\n\n\n\t\t\t\t\t\t��ѡ��\n");
	printf("\t\t\t\t\t\t\t1 �û���¼\n\t\t\t\t\t\t\t2 �û�ע��\n\t\t\t\t\t\t\t3 �˳�\n");
	n=getch();
	if(n=='1'){
		denglu();
	}
	else if(n=='2'){
		system("CLS");
		zhuce();
	}
	else{
		system("CLS");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t��лʹ��,ף��������죡");
		printf("\n\n\n\n");
		sleep(1);
		exit(-1); 
	}
}

int main()
{
	struct yaopin *x,*y,*head;
	FILE *f5;
	int a,b,c,d,e,f,g,h,i;
	char co,ch;
	system("color 30");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t��ӭ����ҩ�����ϵͳ1.0��\n");
	sleep(2);
	system("cls");
	denglujiemian();
	while(1)
	{
		switch(caidan())
		{
			case 1:
				system("CLS");
				fflush(stdin);
				printf("\t\tϵͳ��ҩƷ��Ϣ���£�\n");
				x=shuchu();
				if(x==NULL){
					printf("\t\t\tϵͳ������Ϣ��\n");
					printf("\t\t��Ҫ¼��ҩƷ��Ϣ�𣿣�Y/N��");
					scanf("%c",&co);
					if(co=='Y'){
						head=creatNode();
						shuru(head);
						output(head);
					} 
				}
				else{
					y=x->next;
					output(y);
				}
				printf("\t\t��1�ص��ײ˵�\n");
				a=getch();
				break; 
			case 2:
				system("CLS");
				shanchu();
				printf("\t\t\t��2�ص��ײ˵�\n");
				b=getch();
				break;
			case 3:
				system("CLS");
				chaxun();
				printf("\t\t\t��3�ص��ײ˵�\n");
				c=getch();
				break; 
			case 4:
				system("CLS");
				xiugai();
				printf("\t\t\t��4�ص��ײ˵�\n");
				d=getch();
				break; 
			case 5:
				system("CLS");
				tianjia();
				printf("\t\t\t��5�ص��ײ˵�\n");
				e=getch();
				break; 
			case 6:
				system("CLS");
				paixu();
				printf("\t\t��6�ص��ײ˵�\n");
				f=getch();
				break; 
			case 7:
				system("CLS");
				baobiao();
				printf("\t\t\t��7�ص��ײ˵�\n");
				g=getch();
				break; 
			case 8:
				fflush(stdin);
				system("CLS");
				printf("\t\t\t��ʼ����ɾ�������Ѵ�ҩƷ��Ϣ��ȷ����ʼ����(Y/N)\n");
				char ch,i;
				fflush(stdin);
				scanf("%c",&ch);
				if(ch=='Y')
				{
					printf("\t\t\t��ʼ���ɹ���\n");
					f5=fopen("ҩƷ��Ϣ.txt","wt+");
					fclose(f5);
					printf("\t\t\t��8�ص��ײ˵�\n");
					h=getch();					
				}
				else if(ch=='N')
				{
					printf("\t\t\t��ʼ��ʧ�ܣ�");
					printf("\n\t\t\t��8�ص��ײ˵�\n");
					h=getch();
				}
				break;
			case 9:
				system("CLS");
				tongji();
				printf("\t\t\t��9�ص��ײ˵�\n");
				i=getch();
				break;
			case 0:
				system("CLS");
				printf("\t\t\t\t1 �˳�����\n\t\t\t\t2 �˳���½\n\t\t\t\t");
				ch=getch();
				if(ch=='1'){
					system("CLS");
					printf("\n\n\n\n\n");
					printf("\t\t\t\t\t��лʹ��,ף��������죡");
					printf("\n\n\n\n");
					sleep(1);
					exit(-1);	
				}
				if(ch=='2'){
					system("cls");
					denglujiemian();
				}
				break; 
		}
	}	
}
