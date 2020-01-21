#include<string.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct yaopin)
#define FMT "\t\t\t药品编号：%-3d，药品名称：%-12s，进价：%-6.2f元，售价：%-6.2f元，生产日期：%-15s，保质期：%-15s，库存：%-4d，处方类型：%-5s\n"

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
		printf("\t\t\t是否添加药品（Y/N）：");
		rewind(stdin);
		scanf("%c",&choice);
		if(choice=='N')
		{
			break;
		}
		printf("\t\t\t输入药品编号：");
		scanf("%d",&p1->bianhao); 
		printf("\t\t\t输入药品名称：");
		scanf("%s",&p1->mingzi);
		printf("\t\t\t输入药品进价：");
		scanf("%d",&p1->jinjia); 
		printf("\t\t\t输入药品单价：");
		scanf("%f",&p1->danjia);
		printf("\t\t\t输入药品生产日期：");
		scanf("%s",&p1->shengchanriqi);
		printf("\t\t\t输入药品保质期：");
		scanf("%s",&p1->baozhiqi);
		printf("\t\t\t输入药品库存：");
		scanf("%d",&p1->kucun);
		printf("\t\t\t输入药品处方类型：");
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
				printf("\t\t\t未检索到系统内药品信息！\n");
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
	fp=fopen("药品信息.txt","wt");
	if((fp=fopen("药品信息.txt","wt"))==NULL)
	{
		printf("\t\t\t无法打开文件");
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
	f1=fopen("药品信息.txt","r");
	f2=fopen("药品信息.txt","r");
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
	printf("\t\t请选择查询方式：\n");
	printf("\t\t\t1 按药品编号查询\n");
	printf("\t\t\t2 按药品名称查询\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("\t\t\t请输入需要删除的药品编号：");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->next->bianhao==j)
				{
					printf("药品信息如下：\n"); 
					printf(FMT,t->next->bianhao,t->next->mingzi,t->next->jinjia,t->next->danjia,t->next->shengchanriqi,t->next->baozhiqi,t->next->kucun,t->next->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\t确定删除此药品吗？（Y/N）：");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							printf("\t\t\t删除失败！\n"); 
							break;
						}
						else
						{
							t->next=t->next->next;
							printf("\t\t\t删除成功！\n");
							break; 
						}
					} 
					break;
				} 
			}
			if(flag==0)
			{
				printf("\t\t\t未查找到药品信息！"); 
			}
			p=h->next;
			shuru(p);
			output(p);
			break;
		case 2:
			printf("\t\t\t请输入需要删除的药品名字：");
			scanf("%s",name); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(strcmp(t->mingzi,name)==0);
				{
					printf("药品信息如下：\n"); 
					printf(FMT,t->next->bianhao,t->next->mingzi,t->next->jinjia,t->next->danjia,t->next->shengchanriqi,t->next->baozhiqi,t->next->kucun,t->next->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\t确定删除此药品吗？（Y/N）：");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							printf("\t\t\t删除失败！\n"); 
							break;
						}
						else
						{
							t->next=t->next->next;
							printf("\t\t\t删除成功！\n");
							break; 
						}
					} 
					break;
				} 
			}
			if(flag==0)
			{
				printf("\t\t\t未查找到药品信息！"); 
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
	printf("\t\t\t请选择查询方式：\n");
	printf("\t\t\t\t1 按药品编号查询\n");
	printf("\t\t\t\t2 按药品名称查询\n");
	printf("\t\t\t\t3 按药品处方类型及价格区间查询\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			system("CLS");
			int j,flag=0;
			printf("\t\t\t\t请输入药品编号：");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->bianhao ==j)
				{
					printf("\t\t\t药品信息如下：\n");
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\t未查找到药品信息！"); 
			}
			break;
		case 2:
			system("CLS");
			char name[10];
			flag=0;
			printf("\t\t\t\t请输入药品名称：");
			scanf("%s",name);
			for(t=h;t!=NULL;t=t->next){
				if(strcmp(name,t->mingzi)==0){
					printf("\t\t\t药品信息如下：\n"); 
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\t未查找到药品信息！"); 
			}
			break;
		case 3:
			system("CLS");
			float max,min;
			char cf[10];
			flag=0;
			printf("\t\t\t\t请输入处方类型：\n");
			scanf("%s",cf);
			printf("\t\t\t\t请输入价格区间(输入时先小后大，中间用空格隔开)：");
			scanf("%f%f",&min,&max);
			for(t=h;t!=NULL;t=t->next){
				if(t->danjia>=min && t->danjia<=max && strcmp(cf,t->chufangleixing)==0){
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t\t未查找到药品信息！"); 
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
	printf("\t\t\t请选择查询方式：\n");
	printf("\t\t\t\t1 按药品编号查询\n");
	printf("\t\t\t\t2 按药品名称查询\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("\t\t\t请输入药品编号：");
			scanf("%d",&j); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(t->bianhao ==j)
				{
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\t确定修改药品信息吗？（Y/N）：");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							break;
						}
						else
						{
							printf("\t\t\t请重新输入药品编号：");
							scanf("%d",&t->bianhao);
							printf("\t\t\t请重新输入药品名：");
							scanf("%s",&t->mingzi);
							printf("\t\t\t请重新输入药品进价：");
							scanf("%f",&t->jinjia);
							printf("\t\t\t请重新输入单价：") ;
							scanf("%f",&t->danjia );
							printf("请重新输入生产日期：");
							scanf("%s",&t->shengchanriqi);
							printf("请重新输入保质期：");
							scanf("%s",&t->baozhiqi);
							printf("\t\t\t请重新输入库存：");
							scanf("%d",&t->kucun );
							printf("\t\t\t请重新输入处方类型：");
							scanf("%s",&t->chufangleixing);
							printf("\t\t\t修改情况如下：\n");
							printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
						}
					}
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t未查找到药品信息！"); 
			}
			p=h->next ;
			shuru(p);
			break;
		case 2:
			printf("\t\t\t请输入药品名称：");
			scanf("%s",name); 
			for(t=h;t!=NULL;t=t->next)
			{
				if(strcmp(t->mingzi,name)==0)
				{
					printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
					flag=1;
					while(1)
					{
						printf("\t\t\t确定修改药品信息吗？（Y/N）：");
						rewind(stdin);
						scanf("%c",&choice);
						if(choice=='N')
						{
							break;
						}
						else
						{
							printf("\t\t\t请重新输入药品编号：");
							scanf("%d",&t->bianhao);
							printf("\t\t\t请重新输入药品名：");
							scanf("%s",&t->mingzi);
							printf("\t\t\t请重新输入药品进价：");
							scanf("%f",&t->jinjia);
							printf("\t\t\t请重新输入单价：") ;
							scanf("%f",&t->danjia );
							printf("请重新输入生产日期：");
							scanf("%s",&t->shengchanriqi);
							printf("请重新输入保质期：");
							scanf("%s",&t->baozhiqi);
							printf("\t\t\t请重新输入库存：");
							scanf("%d",&t->kucun );
							printf("\t\t\t请重新输入处方类型：");
							scanf("%s",&t->chufangleixing);
							printf("\t\t\t修改情况如下：\n");
							printf(FMT,t->bianhao,t->mingzi,t->jinjia,t->danjia,t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
						}
					}
					break;
				}
			}
			if(flag==0)
			{
				printf("\t\t\t未查找到药品信息！"); 
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
	char n[10]={"处方"};
	int i=0,j=0,m,ch;
	int c=0,d=0;
	printf("请选择统计项目：\n");
	printf("\t\t1 统计不同处方类型药物种类\n");
	printf("\t\t2 分析库存积压挤压情况\n");
	printf("\t\t3 分析库存不足情况\n");
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
			printf("\t\t统计结果：\n");
			printf("\t\t\t处方类药共%d种，非处方类药共%d种。\n",i,j);
			break;
		case 2:
			system("CLS");
			for(t=h->next;t!=NULL;t=t->next){
				if(t->kucun>=100){
					printf("\t\t\t%s, 药品编号为%d，药品库存为%d\n",t->mingzi,t->bianhao,t->kucun);
					c++;
				}
			}
			if(c==0){
				printf("\t\t\t无药品库存积压情况！\n"); 
			}
			else{
				printf("\t\t\t以上药品库存数大于100件，已造成库存积压，需要减少进货！\n"); 
			}
			break; 
		case 3:
			system("CLS");
			for(t=h->next;t!=NULL;t=t->next){
				if(t->kucun<=20){
					printf("\t\t\t%s, 药品编号为%d，药品库存为%d\n",t->mingzi,t->bianhao,t->kucun);
					d++;
				}
			}
			if(d==0){
				printf("\t\t\t无药品库存不足情况！\n"); 
			}
			else{
				printf("\t\t\t以上药品库存数小于20件，请及时补货！\n"); 
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
	printf("\t\t请选择：\n"); 
	printf("\t\t\t1 药品库存升序排序\n\t\t\t2 药品利润降序排序\n");
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
			printf("\t\t按药品库存将药品升序排列如下：\n");
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
			printf("\t\t按药品利润将药品降序排列如下：\n");
			for(t=h->next;t!=NULL;t=t->next)
			{
				printf("\t\t\t药品编号：%-3d，药品名称：%-12s，利润：%-6.2f元，生产日期：%-15s，保质期：%-15s，库存：%-4d，处方类型：%-5s\n",t->bianhao,t->mingzi,(t->danjia - t->jinjia),t->shengchanriqi,t->baozhiqi,t->kucun,t->chufangleixing);
			}
			break;	
	}	
} 

void baobiao()
{
	struct yaopin *h,*t;
	h=shuchu();
	printf("\t对药品统计后生成报表如下:\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t| **%15s%15s%15s%15s%15s%19s%19s%15s  ** |\n","药品编号","药品名字","药品进价","药品单价","生产日期","保质期","药品库存","处方类型");
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
	printf("\t\t\t请输入添加药品的次序：");
	scanf("%d",&num);
	for(p=head;p!=NULL;p=p->next){
		k++;
		if(k==num-1){
			t=(struct yaopin *)malloc(LEN);
			printf("\t\t\t输入药品编号：");
		    scanf("%d",&t->bianhao);
		    printf("\t\t\t输入药品名称：");
			scanf("%s",&t->mingzi);
			printf("\t\t\t输入药品进价：");
			scanf("%f",&t->jinjia);
	        printf("\t\t\t输入药品单价：");
		    scanf("%f",&t->danjia);
		    printf("\t\t\t输入药品生产日期：");
		    scanf("%s",&t->shengchanriqi);
		    printf("\t\t\t输入药品保质期：");
		    scanf("%s",&t->baozhiqi);
		    printf("\t\t\t输入药品库存：");
		    scanf("%d",&t->kucun);
		    printf("\t\t\t输入药品处方类型：");
		    scanf("%s",&t->chufangleixing);
		    t->next=p->next;
			p->next=t;
			break; 
		}
	}
	printf("\t\t\t添加成功！\n"); 
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
		printf("\t\t\t\t***********欢迎进入药店管理系统**************\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 查看系统内药品信息                   ||\n");
		printf("\t\t\t\t||  2 下架指定药品信息                     ||\n");
		printf("\t\t\t\t||  3 查询指定药品信息                     ||\n");
		printf("\t\t\t\t||  4 修改指定药品信息                     ||\n");
		printf("\t\t\t\t||  5 添加药品                             ||\n");
		printf("\t\t\t\t||  6 药品库存与利润排序                   ||\n");
		printf("\t\t\t\t||  7 打印报表                             ||\n");
		printf("\t\t\t\t||  8 初始化系统                           ||\n");
		printf("\t\t\t\t||  9 统计系统                             ||\n");
		printf("\t\t\t\t||  0 退出                                 ||\n"); 
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t请选择1~9：");
		n=getch();
	}while(n<'0'||n>'9');
	return (n-48);
}

void zhuce()
{
	char meg[20],filename[20];
	while(1){
		printf("\n\n\n\n\n\n\n\t\t\t\t用户注册：\n");
		printf("\t\t\t\t\t请输入用户名：");
		scanf("%s",user1.name);
		strcat(user1.name,".txt");
		fp=fopen(user1.name,"r+");
		if(fp!=NULL){
			printf("\n\t\t\t\t\t给用户已存在！\n");
			fclose(fp);
			denglu();
			break;
		}
		printf("\t\t\t\t\t请输入密码：");
		yincode(user1.code);
		printf("\n\t\t\t\t\t确认密码：");
		yincode(meg);
		while(strcmp(user1.code,meg)!=0){
			printf("\n\t\t\t\t\t密码不一致，请重新输入：\n");
			printf("\t\t\t\t\t请输入密码：");
			yincode(user1.code);
			printf("\n\t\t\t\t\t确认密码：");
			yincode(meg);
		}
		fp=fopen(user1.name,"wt");
		if(fp==NULL){
			printf("\n\t\t\t\t\t注册失败！\n");
			exit(0);
		}
		else{
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t注册成功！\n");
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
        printf("\n\t\t写入文件错误");
        exit(0);
    }
}

void denglu()
{
	char megn[20],megc[10];
	char n;
	int m=2;
	printf("\t\t\t\t用户登录：\n");
	printf("\t\t\t\t\t请输入用户名：");
	scanf("%s",megn);
	strcat(megn,".txt");
	fp=fopen(megn,"r");
	if(fp==NULL){
		printf("\t\t\t\t\t用户不存在，请注册\n");
		printf("\t\t\t\t\t1 注册\n\t\t\t\t\t2 重新登陆\n\t\t\t\t\t3 退出");
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
		printf("\t\t\t\t\t请输入6位密码：");
		yincode(megc);
		fscanf(fp,"%s",user1.code);
		if(strcmp(user1.code,megc)!=0){
			printf("\n\t\t\t\t\t密码错误！\n");
			printf("\t\t\t\t\t1 退出\n\t\t\t\t\t2 重新输入（还剩%d次机会！）\n",m);
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
	printf("\t\t\t\t\t欢迎进入药店管理系统1.0！\n");
	printf("\n\n\n\t\t\t\t\t\t请选择：\n");
	printf("\t\t\t\t\t\t\t1 用户登录\n\t\t\t\t\t\t\t2 用户注册\n\t\t\t\t\t\t\t3 退出\n");
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
		printf("\t\t\t\t\t感谢使用,祝您生活愉快！");
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
	printf("\t\t\t\t\t欢迎进入药店管理系统1.0！\n");
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
				printf("\t\t系统内药品信息如下：\n");
				x=shuchu();
				if(x==NULL){
					printf("\t\t\t系统内无信息！\n");
					printf("\t\t需要录入药品信息吗？（Y/N）");
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
				printf("\t\t按1回到首菜单\n");
				a=getch();
				break; 
			case 2:
				system("CLS");
				shanchu();
				printf("\t\t\t按2回到首菜单\n");
				b=getch();
				break;
			case 3:
				system("CLS");
				chaxun();
				printf("\t\t\t按3回到首菜单\n");
				c=getch();
				break; 
			case 4:
				system("CLS");
				xiugai();
				printf("\t\t\t按4回到首菜单\n");
				d=getch();
				break; 
			case 5:
				system("CLS");
				tianjia();
				printf("\t\t\t按5回到首菜单\n");
				e=getch();
				break; 
			case 6:
				system("CLS");
				paixu();
				printf("\t\t按6回到首菜单\n");
				f=getch();
				break; 
			case 7:
				system("CLS");
				baobiao();
				printf("\t\t\t按7回到首菜单\n");
				g=getch();
				break; 
			case 8:
				fflush(stdin);
				system("CLS");
				printf("\t\t\t初始化会删除所有已存药品信息，确定初始化吗？(Y/N)\n");
				char ch,i;
				fflush(stdin);
				scanf("%c",&ch);
				if(ch=='Y')
				{
					printf("\t\t\t初始化成功！\n");
					f5=fopen("药品信息.txt","wt+");
					fclose(f5);
					printf("\t\t\t按8回到首菜单\n");
					h=getch();					
				}
				else if(ch=='N')
				{
					printf("\t\t\t初始化失败！");
					printf("\n\t\t\t按8回到首菜单\n");
					h=getch();
				}
				break;
			case 9:
				system("CLS");
				tongji();
				printf("\t\t\t按9回到首菜单\n");
				i=getch();
				break;
			case 0:
				system("CLS");
				printf("\t\t\t\t1 退出程序\n\t\t\t\t2 退出登陆\n\t\t\t\t");
				ch=getch();
				if(ch=='1'){
					system("CLS");
					printf("\n\n\n\n\n");
					printf("\t\t\t\t\t感谢使用,祝您生活愉快！");
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
