#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
#define LUN sizeof(struct nba)

struct nba             //定义结构
{
	char name[20];
	int score;
	float rebound;
	int year;
	float high;
	struct nba* next;
};
struct deng
{
	char name[20];
	char ss[20];
}ll; 
int n=0; 
struct nba* create()                                            //输入链表
{
	struct nba* head;
	struct nba* p1, * p2;
	head = (struct nba*)malloc(LUN);
	p1 = p2 = (struct nba*)malloc(LUN);
	head->next = NULL;
	printf("请输入球员姓名： ");
	scanf("%s", p1->name);
	printf("   请输入分数");
	scanf("%d", &p1->score);
	printf("   请输入篮板数：");
	scanf("%f", &p1->rebound);
	printf("   请输入年龄：");
	scanf("%d",&p1->year);
	printf("   请输入身高：");
	scanf("%f",&p1->high);
	while (p1->score != 0)
	{
		n += 1;
		if (n == 1) {
			head->next = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct nba*)malloc(LUN);
		printf("请输入球员姓名： ");
		scanf("%s", p1->name);
		printf("   请输入分数");
		scanf("%d", &p1->score);
		printf("   请输入篮板数：");
		scanf("%f", &p1->rebound);
		printf("   请输入年龄：");
		scanf("%d",&p1->year);
		printf("   请输入身高：");
		scanf("%f",&p1->high);
	}
	p2->next = NULL;
	free(p1);
	printf("个数有%d个！ \n", n);
	return head;
}
void print2(struct nba* head)                                    //输出链表
{
	int i = 1;
	struct nba* p1;
	p1 = head->next;
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t|  编号  姓名  得分  篮板  年龄  身高  \n"); 
	while (p1 != NULL)
	{
		printf("|\t\t\t\t\t%6d", i);
		printf("\t\t\t\t\t%6s", p1->name);
		printf("\t\t\t\t\t%6d", p1->score);
		printf("\t\t\t\t\t%5.1f", p1->rebound);
		printf("\t\t\t\t\t%6d",p1->year);
		printf("\t\t\t\t\t%5.1f|\n",p1->high);
		p1 = p1->next;
		i++;
	}
	printf("\t\t\t\t\t|---------------------------------------------------------|\n");
	free(p1);
}
void print(struct nba* head)                                    //输出链表
{
	int i = 1;
	struct nba* p1;
	p1 = head->next;
	while (p1 != NULL)
	{
		printf("第%d名球员是：", i);
		printf("%s", p1->name);
		printf("  得分：%d", p1->score);
		printf("  篮板：%.1f", p1->rebound);
		printf("  年龄：%d",p1->year);
		printf("  身高：%.1f\n",p1->high);
		p1 = p1->next;
		i++;
	}
	free(p1);
}
void denglu(char mm[])             //输入密码 
{
	int i = 0;
	while ( i < 50 ){
		mm[i] = getch();
		if (mm[i] == '\r'){
			break;	
		} 
		else if (mm[i] == '\b') { 
			i=i-1; 
			printf("\b \b");
		} 
		else {
			i=i+1;
			printf("*");
		}
	}
	mm[i]='\0';
//	printf("mm = %s",mm);

}
int  landing()                //登陆函数
{
	int num2,num3,num4=0,icount=2;
	FILE *fp;
	FILE *fp2;
	char mima[10]="123456",mima2[10];
	char yongh[20],mima3[20],mima4[20],yongh2[20];
	scanf("%d",&num2);
//	fflush(stdin);
	system("cls");
	switch (num2)
	{
		case 1:
			printf("\n\t\t\t\t\t请输入管理员密码：(密码为6位)\n\t\t\t\t\t");
			fp2=fopen("guanliyuan.txt","rt+");
			if(fp2 != NULL)
				printf("打开成功");
			denglu(mima2);
			fscanf(fp2,"%s",ll.ss);
			printf("成功");
			printf("\nmami2 = %s, ll.ss = %s\n", mima2, ll.ss);
			if(!strcmp(mima2,ll.ss))
			{
				printf("\n\t\t\t\t\t管理员登录成功！\n");
				getchar();
				num3=1;
				system("cls");
			}
			else if(strcmp(mima,mima2))
			{
				while(icount>0)
				{
					printf("密码错误，请重新输入，你还有%d次机会\n", icount);
//					for(num4=0;num4<6;num4++)
//					{
//					mima2[num4]=getch();
//					printf("*");
//					}
					denglu(mima2);
					getchar();
					icount--;
					if(!strcmp(mima,mima2))
			        {
					printf("\n\t\t\t\t\t管理员登录成功！\n");
					getchar();
					num3=1;
					system("cls");
					break;
					}
					if(icount==0)
					{
						printf("你的次数已经使用完毕！");
						num3=4; 
						break;
					}
				}
			}
			fclose(fp2);
			break;
		case 2:
			printf("\n\n\t\t\t\t\t用户名：");
			scanf("%s",yongh);
			strcat(yongh,".txt");
			fp=fopen(yongh,"r");
			if(fp==NULL){
				printf("该用户名不存在，请注册！或者 游客登陆！\n");
				getchar();
				break; 
			}
			printf("\n\t\t\t\t\t 密码：");
//			for(num4=0;num4<6;num4++){
//				mima3[num4]=getch();
//				printf("*");
//			}
			denglu(mima3);
			fscanf(fp,"%s",ll.ss);
			if(strcmp(ll.ss,mima3))
			{
				while(icount>0)
				{
					printf("密码错误，请重新输入，你还有%d次机会\n", icount);
					getchar();
//					for(num4=0;num4<6;num4++)
//					{
//					mima3[num4]=getch();
//					printf("*");
//					}
					denglu(mima3);
					icount--;
					if(!strcmp(mima,mima2))
			        {
					printf("\n\t\t\t\t\t登录成功！\n");
					getchar();
					num3=2;
					system("cls");
					break;
					}
					if(icount==0)
					{
						printf("你的次数已经使用完毕！");
						num3=4; 
						getchar();
						system("cls");
						break;
					}
				}
				
			}else{
				printf("\n\t\t\t\t\t登录成功！\n");
				getchar();
				num3=2;
				system("cls");
				break;
			}
			break;
		case 3:
			printf("\n\t\t\t\t\t游客登录成功!\n");
			num3=3;
			fflush(stdin);
			getchar();
			system("cls");
			break;
		case 4:
			FILE *fp3;
			char mima4[20],yhu[20];
			int p = 0;
			fp3 = fopen("quiyuan.txt","r");
			if (fp3 == NULL) {
				p = 1;
				fp3 = fopen("quiyuan.txt", "a");
			}
			fclose(fp3);
			printf("\t\t\t\t请输入用户名：");
			gets(ll.name);
			if (p == 0);
			{
				fp = fopen("quiyuan.txt", "r");
				while (!feof(fp))
				{
					fscanf(fp, " %s %s\n", yhu, ll.ss);
					{
						if (!strcmp(ll.name,yhu))
						{
							printf("\t\t\t\t  已存在该球员，无需重复录入！\n");
							printf("\t\t\t\t  任意键返回上层！");
							getch();
							fclose(fp3);
							landing();
						}
					}
				}
			}
			fp3 = fopen("quiyuan.txt", "a");
			printf("\t\t\t\t\t请输入密码：");
			denglu(ll.ss);
			printf("\n\t\t\t\t\t确认密码：");
			denglu(mima);
			while (strcmp(mima, ll.ss) != 0) {
				printf("\n\t\t\t\t\t密码不一致，请重新输入：\n");
				printf("\t\t\t\t\t请输入密码：");
				denglu(mima);
				printf("\n\t\t\t\t\t确认密码：");
				denglu(ll.ss);
			}
			fprintf(fp, " %s %s\n", ll.name, ll.ss);
			printf("注册成功！");
			num3 = 4;
			fclose(fp);
			getchar();
			system("cls");
//			FILE *fp;
//			char mima[20];
//			while(1){
//				printf("\t\t\t\t请输入用户名：");
//				fflush(stdin);
////				scanf("%s ",ll.name);
//				gets(ll.name);
//				strcat(ll.name,".txt");
//				printf("%s",ll.name);
//				fp=fopen(ll.name,"r+");
//				if(fp!=NULL){
//					printf("用户已经存在！\n");
//					fclose(fp);
//					getchar();
//					num3=landing();
//					break;
//				}
//				printf("\t\t\t\t\t请输入密码：");
//				denglu(ll.ss);
//				printf("\n\t\t\t\t\t确认密码：");
////				fflush(stdin);
//				denglu(mima);
//				while(strcmp(mima,ll.ss)!=0){
//					printf("\n\t\t\t\t\t密码不一致，请重新输入：\n");
//					printf("\t\t\t\t\t请输入密码：");
//					denglu(mima);
//					printf("\n\t\t\t\t\t确认密码：");
//					denglu(ll.ss);
//				}
//				printf("注册成功！");
//				fp=fopen(ll.name,"w+");
//				num3=4;
//				fprintf(fp,"%s",ll.ss);
//				fclose(fp);
//				getchar();
//				system("cls");
//			} 
//			fclose(fp);
			break;					
	}
	return num3;
}
void  compare(struct nba* head)     //对比
{
	int num;
	struct nba* stu1, * stu2, * stu3;
	char name2[10], name3[10];
	stu1 = head->next;
	printf("请输入要对比的第一位球员\n");
	scanf("%s", name2);
	printf("请输入要对比的第二位球员\n");
	scanf("%s", name3);
	system("cls");
	while (stu1 != NULL)
	{
		if (!strcmp(name2, stu1->name));
		{
			stu2 = stu1;
		}
		stu1 = stu1->next;
	}
	stu1 = head->next;
	while (stu1 != NULL)
	{
		if (!strcmp(name3, stu1->name))
		{
			stu3 = stu1;
		}
		stu1 = stu1->next;
	}
	printf("\n得分对比：\n");
	if (stu2->score > stu3->score)
	{
		printf("%s胜！\n", stu2->name);
	}
	else if(stu2->score<stu3->score)
	{
		printf("%s胜！\n", stu3->name);
	}
	else {
		printf("一样多");
	}

	printf("\n篮板对比\n");
	if (stu2->rebound > stu3->rebound)
	{
		printf("%s胜！\n", stu2->name);
	}
	else if(stu2->rebound<stu3->rebound)
	{
		printf("%s胜！\n", stu3->name);
	}
	else {
		printf("一样多");
	}

	printf("\n年龄对比\n");
	if (stu2->year > stu3->year) {
		printf("%s年龄大", stu2->name);
	}
	else if(stu2->year<stu3->year) {
		printf("%s年龄大", stu3->name);
	}
	else {
		printf("年龄一样大");
	}

	printf("\n身高对比\n");
	if (stu2->high > stu3->high) {
		printf("%s高", stu2->name);
	}
	else if(stu2->high<stu3->high)
	{
		printf("%s高", stu3->name);
	}
	else {
		printf("一样高");
	}
}
void sort(struct nba* head)      //排序
{
	int k1, k2,k3,k4;
	float f1, f2;
	char na[20];
	struct nba* p1, * p2;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t按得分排序请按1；按篮板排序请按2：按年龄排序请按3：按身高排序请按4：");
	scanf("%d", &k1);
	printf("\n\t\t\t\t按升序排序请按1：按降序排序请按2：");
	scanf("%d", &k2);
	switch (k1)
	{
	case 1:
		switch (k2)
		{
		case 1:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->score > p2->score) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		case 2:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->score < p2->score) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		}
		break;
	case 2:
		switch (k2)
		{
		case 1:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->rebound > p2->rebound) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		case 2:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->rebound < p2->rebound) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		}
		break;
	case 3:
		switch (k2) {
		case 1:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->year > p2->year) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		case 2:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->year < p2->year) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		}
		break;
	case 4:
		switch (k2)
		{
		case 1:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->high > p2->high) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		case 2:
			for (p1 = head->next; p1->next != NULL; p1 = p1->next) {
				for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
					if (p1->high < p2->high) {
						k3 = p1->score;
						p1->score = p2->score;
						p2->score = k3;

						k4 = p1->year;
						p1->year = p2->year;
						p2->year = k4;

						f1 = p1->high;
						p1->high = p2->high;
						p2->high = f1;

						f2 = p1->rebound;
						p1->rebound = p2->rebound;
						p2->rebound = f2;

						strcpy(na, p1->name);
						strcpy(p1->name, p2->name);
						strcpy(p2->name, na);
					}
				}
			}
			break;
		}
		break;
	}
	print(head);
}
void modify(struct nba* head)                           //修改函数
{
	struct nba* stu;
	char newname[20];
	int sc, sw;
	float re;
	stu = head->next;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t请输入需要修改的球员：");
	scanf("%s", newname);
	while (stu != NULL)
	{
		if (!strcmp(stu->name, newname))
		{
			break;
		}
		stu = stu->next;
	}
	printf("修改得分选择1，修改篮板选择2：");
	scanf("%d", &sw);
	switch (sw)
	{
	case 1:
		printf("请输入修改的分数：\n");
		scanf("%d", &sc);
		stu->score = sc;
		break;
	case 2:
		printf("请输入修改的篮板：\n");
		scanf("%f", &re);
		stu->rebound = re;
		break;
	}
	printf("链表修改完毕！\n");
}
void query(struct nba* head)                //查找函数
{	int sw,flag=0,ssc,min,max;
	char qname[20];	
	float ssr,smin,smax;
	struct nba* stu;
	stu = head->next;
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t按姓名查找请按1：按得分查找请按2：按年龄区间查找请按3： 按身高区间查找请按4：按年龄和身高区间查找请按5：按得分与篮板结合查找请按6：\n");
	printf("\t\t\t\t");
	scanf("%d", &sw);
	system("cls");
	switch(sw)
	{
		case 1:
			printf("\t\t\t\t请输入想要查找的姓名：\n");
			scanf("%s", qname);
			while (stu != NULL)
			{
				if (!strcmp(qname, stu->name))
				{
					printf("查询信息：");
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("球员不存在！！");
			}
			break;
		case 2:
			printf("\t\t\t\t请输入查找的球员的得分：\n");
			scanf("%d", &ssc);
			while (stu != NULL)
			{
				if (stu->score == ssc)
				{
					printf("查询信息：");
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("输入的姓名不存在！！");
			}
			break;
		case 3:
			printf("\t\t\t\t请输入要查询球员的年龄最大值：") ;
			scanf("%d",&max);
			printf("\n\t\t\t\t请输入要查询球员的年龄最小值：");
			scanf("%d",&min);
			printf("查询信息：");
			if(stu!=NULL){
				if(stu->year>=min&&stu->year<=max){
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("球员不存在！！");
			}
			break;
			break;
		case 4:
			printf("\t\t\t\t请输入要查询球员的身高最大值：") ;
			scanf("%f",&smax);
			printf("\n\t\t\t\t请输入要查询球员的身高最小值：");
			scanf("%f",&smin);
			if(stu!=NULL){
				if(stu->high>=smin&&stu->high<=smax){
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("球员不存在！！");
			}
			break;
			break;
		case 5:
			printf("\t\t\t\t请输入要查询球员的身高最大值：") ;
			scanf("%f",&smax);
			printf("\n\t\t\t\t请输入要查询球员的身高最小值：");
			scanf("%f",&smin);
			printf("\t\t\t\t请输入要查询球员的年龄最大值：") ;
			scanf("%d",&max);
			printf("\n\t\t\t\t请输入要查询球员的年龄最小值：");
			scanf("%d",&min);
			if(stu!=NULL){
				if(stu->high>=smin&&stu->high<=smax&&stu->year>=min&&stu->year<=max){
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("球员不存在！！");
			}
			break;
			break;
		case 6: 
			printf("\t\t\t\t请输入查找球员的得分：");
			scanf("%d", &ssc);
			printf("\n\t\t\t\t请输入查找球员的篮板：\n");
			scanf("%f", &ssr);
			system("cls");
			while (stu != NULL)
			{
				if (stu->rebound == ssr && stu->rebound == ssr)
				{
					printf("查询信息：");
					puts(stu->name);
					printf("  得分：%d", stu->score);
					printf("  篮板：%.1f", stu->rebound);
					printf("  年龄：%d",stu->year);
					printf("  身高：%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("球员不存在！！");
			}
			break;
	}
}	
struct nba* insert(struct nba* head)       //插入新球员
{
	struct nba* stu, * d;
	d = (struct  nba*)malloc(sizeof(LUN));
	printf("请输入需要加入的球员信息！\n");
	printf("请输入球员姓名：");
	scanf("%s", d->name);
	printf("   请输入球员分数：");
	scanf("%d", &d->score);
	printf("   请输入球员篮板：");
	scanf("%f", &d->rebound);
	printf("   请输入球员年龄：");
	scanf("%d",&d->year);
	printf("   请输入球员身高：");
	scanf("%f",&d->high);
	system("cls");
	stu = head->next;
	int s;
	char ssname[20];
	printf("头插请按1，尾插请按2，插在某个球员后面请按3：\n");
	scanf("%d", &s);
	system("cls");
	switch (s)
	{
	case 1:
		d->next = stu;
		head->next = d;
		printf("头插成功！\n");
		break;
	case 2:
		while (stu->next != NULL)
		{
			stu = stu->next;
		}
		stu->next = d;
		d->next = NULL;
		printf("尾插成功！\n");
		break;
	case 3:
		printf("请输入要插在哪一个球员之后：\n");
		scanf("%s", ssname);
		while (stu != NULL)
		{
			if (!strcmp(ssname, stu->name))
			{
				d->next = stu->next;
				stu->next = d;
				break;
			}
			stu = stu->next;
		}
		break;
	}
	getchar();
	system("cls");
	return head;
}
void deletee(struct nba* head)      //删除函数
{
	struct nba* stu, * p1;
	stu = head->next;
	char s2name[20];
	printf("请输入要删除的球员姓名：\n");
	scanf("%s", s2name);
	if (stu != NULL)
	{
		if (!strcmp(s2name, stu->name))
		{
			p1->next = stu->next;
			printf("球员已删除！\n");
			return ;
		}
		p1 = stu;
		stu = stu->next;
	}else{
		printf("不存在该球员！\n");
	}
}
void filee(struct nba* stu)             //书写文件函数
{
	FILE *fp;
	char fname[20];
	fp = fopen("fi.txt", "w+");
	struct nba* head;
	head = stu->next;
	while (head != NULL)
	{
		fprintf(fp, "%s ", head->name);
		fprintf(fp, "%d ", head->score);
		fprintf(fp, "%.2f ", head->rebound);
		fprintf(fp, "%d ",head->year);
		fprintf(fp,"%.2f ",head->high);
		head = head->next;
	}
	printf("文件写入成功！\n");
	fclose(fp);
}
struct nba* du()                           //读出文件 
{
	n = 0;
	char fname[20],ch;
	struct nba* head, * p1, * p2;
	FILE *fp;
	fp = fopen("fi.txt", "r");	
	if(fp != NULL)
		printf("打开成功！\n"); 	
	p1 = head = (struct nba*)malloc(sizeof(LUN));
	head->next = NULL;
	p1 = head;
	while (ch=fgetc(fp)!=EOF)
	//while (!feof(fp)) 
	{
		n++;
		p2 = (struct nba*)malloc(sizeof(LUN));
		printf("ddd");
//		fscanf(fp,"%s ", p2->name);
//		fscanf(fp,"%d ", &p2->score);
//		fscanf(fp,"%f ", &p2->rebound);
//		fscanf(fp,"%d ",&p2->year);
//		fscanf(fp,"%f ",&p2->high);
		fscanf(fp,"%s %d %f %d %f\n",p2->name,&p2->score,&p2->rebound,&p2->year,&p2->high);
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp);
	p2->next = NULL;
	printf("文件读取成功！！！有%d个球员", n);
	fflush(stdin);
	getchar();
	system("cls");
	return head;
}
void face()         //游客 
{
	printf("\n\n\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\t\t\t\t\t            |           1-显示所有球员信息             |\n");
	printf("\t\t\t\t\t            |           2-查询球员信息                 |\n");
	printf("\t\t\t\t\t            |           3-按条件顺序输出球员信息       |\n");
	printf("\t\t\t\t\t            |           4-球员信息统计                 |\n");
	printf("\t\t\t\t\t            |           5-球员对比                     |\n");
	printf("\t\t\t\t\t            |           6-退出                         |\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\n\n\n");
}
void face2()                                           //管理员 
{
	printf("\n\n\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\t\t\t\t\t            |           1-显示所有球员信息             |\n");
	printf("\t\t\t\t\t            |           2-查询球员信息                 |\n");
	printf("\t\t\t\t\t            |           3-将数据读入到文件             |\n");
	printf("\t\t\t\t\t            |           4-修改某个球员信息             |\n");
	printf("\t\t\t\t\t            |           5-删除某个球员信息             |\n");
	printf("\t\t\t\t\t            |           6-增添新球员信息               |\n");
	printf("\t\t\t\t\t            |           7-按条件顺序输出球员信息       |\n");
	printf("\t\t\t\t\t            |           8-球员信息统计                 |\n");
	printf("\t\t\t\t\t            |           9-球员对比                     |\n");
	printf("\t\t\t\t\t            |           10-退出                        |\n");
	printf("\t\t\t\t\t            ********************************************\n");

	printf("\n\n\n");
}
void face3()                //
{
	printf("\t\t\t\t\t******************************************\n");
	printf("\t\t\t\t\t------------------------------------------\n\n\n");
	printf("\t\t\t\t\t          1,手动录入球员信息              \n");
	printf("\t\t\t\t\t          2,文件读出球员信息              \n\n\n");
	printf("\t\t\t\t\t------------------------------------------\n");
	printf("\t\t\t\t\t******************************************\n\n");
	printf("\t\t\t\t\t");
}
void face4()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t\t欢迎使用NBA管理系统            \n\n\n\n");
}
void face5()       //球员 
{
	printf("\t\t\t\t\t******************************************\n");
	printf("\t\t\t\t\t------------------------------------------\n\n\n");
	printf("\t\t\t\t\t          1,显示所有球员信息              \n");
	printf("\t\t\t\t\t          2,查询球员信息                  \n");
	printf("\t\t\t\t\t          3,按条件顺序输出球员信息        \n");
	printf("\t\t\t\t\t          4,球员对比                      \n");
	printf("\t\t\t\t\t          5,修改自己的信息              \n");
	printf("\t\t\t\t\t          6,退出                          \n");
	printf("\t\t\t\t\t******************************************\n");
} 
void face6()           //登录 
{	
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************************\n\n");
	printf("\t\t\t\t\t                     登录                      \n");
	printf("\t\t\t\t\t                 1,管理员登录                 \n");
	printf("\t\t\t\t\t                 2,球员登录                   \n");
	printf("\t\t\t\t\t                 3,游客登录                   \n");
	printf("\t\t\t\t\t                 4,注册（只有球员才可以注册） \n"); 
	printf("\t\t\t\t\t**********************************************\n\n");
	printf("\t\t\t\t\t");

}
void you(){
	struct nba * head;
	int num1,flag=0;
//	printf("qqq");
	head=du();
	while(flag!=1){
		face();
		scanf("%d",&num1);
		switch (num1){
			case 1://1-显示所有球员信息
				print(head);
				break;
			case 2://2-查询球员信息
				query(head);
				break;
			case 3://3-按条件顺序输出球员信息
				sort(head);
				break;
			case 4:
				print2(head);
				break;
			case 5://5-球员对比
				compare(head);
				break;
			case 6://10-退出
				flag=1;
				break;				
		}
		getchar();
		getchar();
		system("cls");
	}
}
void qu(){
	struct nba*head;
	head=du();
	int num1,flag=0;
	while(flag!=1){
		face5();
		scanf("%d",&num1);
		switch (num1){
			case 1:
				print(head);
				break;
			case 2://2-查询球员信息
				query(head);
				break;
			case 3://3,按条件顺序输出球员信息
				sort(head);
				break;
			case 4://4,球员对比
				compare(head);
				break;
			case 5://5,修改自己的信息
			case 6:	//10-退出
				flag=1;
				break;					
		}
		getchar();
		getchar();
		system("cls");	
	}
}
struct nba* guan(){
	int num5;
	face3();
	struct nba*head;
	scanf("%d",&num5);
	switch(num5){
		case 1:
			head=create();
			break;
		case 2:
			head=du();
			break;
	}
	return head;
}
void guan2(struct nba*head){
	int num1,flag=0;
	while(flag!=1){
		face2();                                                               
		scanf("%d",&num1);
		switch (num1){
			case 1://1-显示所有球员信息
				print(head);
				break;
			case 2://2-查询球员信息
				query(head);
				break;
			case 3://3-将数据读入到文件
				filee(head);
				break;
			case 4://4-修改某个球员信息
				modify(head);
				break;
			case 5://5-删除某个球员信息
				deletee(head);
				break;
			case 6://6-增添新球员信息
				insert(head);
				break;
			case 7://7-按条件顺序输出球员信息
				sort(head);
				break;
			case 8://8-球员信息格式化输出
				print2(head);
				break; 
			case 9://9-球员对比
				compare(head);
				break;
			case 10://10-退出
				flag=1;
				break;						
		}
		getchar();
		getchar();
		system("cls");
	}
}
int main()
{
	struct nba*head;
	int c;
	system("color E2");
	face4();
	getchar();
	system("cls");
	face6();
	c=landing();
	if(c==1){
		head=guan();
		guan2(head);
	}else if(c==2){
		qu();
	}else if(c==3){
		you();
	}else {
		exit(1);
	}
}
