#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
#define LUN sizeof(struct nba)

struct nba             //����ṹ
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
struct nba* create()                                            //��������
{
	struct nba* head;
	struct nba* p1, * p2;
	head = (struct nba*)malloc(LUN);
	p1 = p2 = (struct nba*)malloc(LUN);
	head->next = NULL;
	printf("��������Ա������ ");
	scanf("%s", p1->name);
	printf("   ���������");
	scanf("%d", &p1->score);
	printf("   ��������������");
	scanf("%f", &p1->rebound);
	printf("   ���������䣺");
	scanf("%d",&p1->year);
	printf("   ��������ߣ�");
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
		printf("��������Ա������ ");
		scanf("%s", p1->name);
		printf("   ���������");
		scanf("%d", &p1->score);
		printf("   ��������������");
		scanf("%f", &p1->rebound);
		printf("   ���������䣺");
		scanf("%d",&p1->year);
		printf("   ��������ߣ�");
		scanf("%f",&p1->high);
	}
	p2->next = NULL;
	free(p1);
	printf("������%d���� \n", n);
	return head;
}
void print2(struct nba* head)                                    //�������
{
	int i = 1;
	struct nba* p1;
	p1 = head->next;
	printf("\t\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t|  ���  ����  �÷�  ����  ����  ���  \n"); 
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
void print(struct nba* head)                                    //�������
{
	int i = 1;
	struct nba* p1;
	p1 = head->next;
	while (p1 != NULL)
	{
		printf("��%d����Ա�ǣ�", i);
		printf("%s", p1->name);
		printf("  �÷֣�%d", p1->score);
		printf("  ���壺%.1f", p1->rebound);
		printf("  ���䣺%d",p1->year);
		printf("  ��ߣ�%.1f\n",p1->high);
		p1 = p1->next;
		i++;
	}
	free(p1);
}
void denglu(char mm[])             //�������� 
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
int  landing()                //��½����
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
			printf("\n\t\t\t\t\t���������Ա���룺(����Ϊ6λ)\n\t\t\t\t\t");
			fp2=fopen("guanliyuan.txt","rt+");
			if(fp2 != NULL)
				printf("�򿪳ɹ�");
			denglu(mima2);
			fscanf(fp2,"%s",ll.ss);
			printf("�ɹ�");
			printf("\nmami2 = %s, ll.ss = %s\n", mima2, ll.ss);
			if(!strcmp(mima2,ll.ss))
			{
				printf("\n\t\t\t\t\t����Ա��¼�ɹ���\n");
				getchar();
				num3=1;
				system("cls");
			}
			else if(strcmp(mima,mima2))
			{
				while(icount>0)
				{
					printf("����������������룬�㻹��%d�λ���\n", icount);
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
					printf("\n\t\t\t\t\t����Ա��¼�ɹ���\n");
					getchar();
					num3=1;
					system("cls");
					break;
					}
					if(icount==0)
					{
						printf("��Ĵ����Ѿ�ʹ����ϣ�");
						num3=4; 
						break;
					}
				}
			}
			fclose(fp2);
			break;
		case 2:
			printf("\n\n\t\t\t\t\t�û�����");
			scanf("%s",yongh);
			strcat(yongh,".txt");
			fp=fopen(yongh,"r");
			if(fp==NULL){
				printf("���û��������ڣ���ע�ᣡ���� �ο͵�½��\n");
				getchar();
				break; 
			}
			printf("\n\t\t\t\t\t ���룺");
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
					printf("����������������룬�㻹��%d�λ���\n", icount);
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
					printf("\n\t\t\t\t\t��¼�ɹ���\n");
					getchar();
					num3=2;
					system("cls");
					break;
					}
					if(icount==0)
					{
						printf("��Ĵ����Ѿ�ʹ����ϣ�");
						num3=4; 
						getchar();
						system("cls");
						break;
					}
				}
				
			}else{
				printf("\n\t\t\t\t\t��¼�ɹ���\n");
				getchar();
				num3=2;
				system("cls");
				break;
			}
			break;
		case 3:
			printf("\n\t\t\t\t\t�ο͵�¼�ɹ�!\n");
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
			printf("\t\t\t\t�������û�����");
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
							printf("\t\t\t\t  �Ѵ��ڸ���Ա�������ظ�¼�룡\n");
							printf("\t\t\t\t  ����������ϲ㣡");
							getch();
							fclose(fp3);
							landing();
						}
					}
				}
			}
			fp3 = fopen("quiyuan.txt", "a");
			printf("\t\t\t\t\t���������룺");
			denglu(ll.ss);
			printf("\n\t\t\t\t\tȷ�����룺");
			denglu(mima);
			while (strcmp(mima, ll.ss) != 0) {
				printf("\n\t\t\t\t\t���벻һ�£����������룺\n");
				printf("\t\t\t\t\t���������룺");
				denglu(mima);
				printf("\n\t\t\t\t\tȷ�����룺");
				denglu(ll.ss);
			}
			fprintf(fp, " %s %s\n", ll.name, ll.ss);
			printf("ע��ɹ���");
			num3 = 4;
			fclose(fp);
			getchar();
			system("cls");
//			FILE *fp;
//			char mima[20];
//			while(1){
//				printf("\t\t\t\t�������û�����");
//				fflush(stdin);
////				scanf("%s ",ll.name);
//				gets(ll.name);
//				strcat(ll.name,".txt");
//				printf("%s",ll.name);
//				fp=fopen(ll.name,"r+");
//				if(fp!=NULL){
//					printf("�û��Ѿ����ڣ�\n");
//					fclose(fp);
//					getchar();
//					num3=landing();
//					break;
//				}
//				printf("\t\t\t\t\t���������룺");
//				denglu(ll.ss);
//				printf("\n\t\t\t\t\tȷ�����룺");
////				fflush(stdin);
//				denglu(mima);
//				while(strcmp(mima,ll.ss)!=0){
//					printf("\n\t\t\t\t\t���벻һ�£����������룺\n");
//					printf("\t\t\t\t\t���������룺");
//					denglu(mima);
//					printf("\n\t\t\t\t\tȷ�����룺");
//					denglu(ll.ss);
//				}
//				printf("ע��ɹ���");
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
void  compare(struct nba* head)     //�Ա�
{
	int num;
	struct nba* stu1, * stu2, * stu3;
	char name2[10], name3[10];
	stu1 = head->next;
	printf("������Ҫ�Աȵĵ�һλ��Ա\n");
	scanf("%s", name2);
	printf("������Ҫ�Աȵĵڶ�λ��Ա\n");
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
	printf("\n�÷ֶԱȣ�\n");
	if (stu2->score > stu3->score)
	{
		printf("%sʤ��\n", stu2->name);
	}
	else if(stu2->score<stu3->score)
	{
		printf("%sʤ��\n", stu3->name);
	}
	else {
		printf("һ����");
	}

	printf("\n����Ա�\n");
	if (stu2->rebound > stu3->rebound)
	{
		printf("%sʤ��\n", stu2->name);
	}
	else if(stu2->rebound<stu3->rebound)
	{
		printf("%sʤ��\n", stu3->name);
	}
	else {
		printf("һ����");
	}

	printf("\n����Ա�\n");
	if (stu2->year > stu3->year) {
		printf("%s�����", stu2->name);
	}
	else if(stu2->year<stu3->year) {
		printf("%s�����", stu3->name);
	}
	else {
		printf("����һ����");
	}

	printf("\n��߶Ա�\n");
	if (stu2->high > stu3->high) {
		printf("%s��", stu2->name);
	}
	else if(stu2->high<stu3->high)
	{
		printf("%s��", stu3->name);
	}
	else {
		printf("һ����");
	}
}
void sort(struct nba* head)      //����
{
	int k1, k2,k3,k4;
	float f1, f2;
	char na[20];
	struct nba* p1, * p2;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t���÷������밴1�������������밴2�������������밴3������������밴4��");
	scanf("%d", &k1);
	printf("\n\t\t\t\t�����������밴1�������������밴2��");
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
void modify(struct nba* head)                           //�޸ĺ���
{
	struct nba* stu;
	char newname[20];
	int sc, sw;
	float re;
	stu = head->next;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t��������Ҫ�޸ĵ���Ա��");
	scanf("%s", newname);
	while (stu != NULL)
	{
		if (!strcmp(stu->name, newname))
		{
			break;
		}
		stu = stu->next;
	}
	printf("�޸ĵ÷�ѡ��1���޸�����ѡ��2��");
	scanf("%d", &sw);
	switch (sw)
	{
	case 1:
		printf("�������޸ĵķ�����\n");
		scanf("%d", &sc);
		stu->score = sc;
		break;
	case 2:
		printf("�������޸ĵ����壺\n");
		scanf("%f", &re);
		stu->rebound = re;
		break;
	}
	printf("�����޸���ϣ�\n");
}
void query(struct nba* head)                //���Һ���
{	int sw,flag=0,ssc,min,max;
	char qname[20];	
	float ssr,smin,smax;
	struct nba* stu;
	stu = head->next;
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t�����������밴1�����÷ֲ����밴2����������������밴3�� �������������밴4��������������������밴5�����÷��������ϲ����밴6��\n");
	printf("\t\t\t\t");
	scanf("%d", &sw);
	system("cls");
	switch(sw)
	{
		case 1:
			printf("\t\t\t\t��������Ҫ���ҵ�������\n");
			scanf("%s", qname);
			while (stu != NULL)
			{
				if (!strcmp(qname, stu->name))
				{
					printf("��ѯ��Ϣ��");
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("��Ա�����ڣ���");
			}
			break;
		case 2:
			printf("\t\t\t\t��������ҵ���Ա�ĵ÷֣�\n");
			scanf("%d", &ssc);
			while (stu != NULL)
			{
				if (stu->score == ssc)
				{
					printf("��ѯ��Ϣ��");
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("��������������ڣ���");
			}
			break;
		case 3:
			printf("\t\t\t\t������Ҫ��ѯ��Ա���������ֵ��") ;
			scanf("%d",&max);
			printf("\n\t\t\t\t������Ҫ��ѯ��Ա��������Сֵ��");
			scanf("%d",&min);
			printf("��ѯ��Ϣ��");
			if(stu!=NULL){
				if(stu->year>=min&&stu->year<=max){
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("��Ա�����ڣ���");
			}
			break;
			break;
		case 4:
			printf("\t\t\t\t������Ҫ��ѯ��Ա��������ֵ��") ;
			scanf("%f",&smax);
			printf("\n\t\t\t\t������Ҫ��ѯ��Ա�������Сֵ��");
			scanf("%f",&smin);
			if(stu!=NULL){
				if(stu->high>=smin&&stu->high<=smax){
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("��Ա�����ڣ���");
			}
			break;
			break;
		case 5:
			printf("\t\t\t\t������Ҫ��ѯ��Ա��������ֵ��") ;
			scanf("%f",&smax);
			printf("\n\t\t\t\t������Ҫ��ѯ��Ա�������Сֵ��");
			scanf("%f",&smin);
			printf("\t\t\t\t������Ҫ��ѯ��Ա���������ֵ��") ;
			scanf("%d",&max);
			printf("\n\t\t\t\t������Ҫ��ѯ��Ա��������Сֵ��");
			scanf("%d",&min);
			if(stu!=NULL){
				if(stu->high>=smin&&stu->high<=smax&&stu->year>=min&&stu->year<=max){
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag=1;
				}
				stu=stu->next;
			}
			if (flag = 0)
			{
				printf("��Ա�����ڣ���");
			}
			break;
			break;
		case 6: 
			printf("\t\t\t\t�����������Ա�ĵ÷֣�");
			scanf("%d", &ssc);
			printf("\n\t\t\t\t�����������Ա�����壺\n");
			scanf("%f", &ssr);
			system("cls");
			while (stu != NULL)
			{
				if (stu->rebound == ssr && stu->rebound == ssr)
				{
					printf("��ѯ��Ϣ��");
					puts(stu->name);
					printf("  �÷֣�%d", stu->score);
					printf("  ���壺%.1f", stu->rebound);
					printf("  ���䣺%d",stu->year);
					printf("  ��ߣ�%.1f\n",stu->high);
					flag = 1;
					break;
				}
				stu = stu->next;
			}
			if (flag = 0)
			{
				printf("��Ա�����ڣ���");
			}
			break;
	}
}	
struct nba* insert(struct nba* head)       //��������Ա
{
	struct nba* stu, * d;
	d = (struct  nba*)malloc(sizeof(LUN));
	printf("��������Ҫ�������Ա��Ϣ��\n");
	printf("��������Ա������");
	scanf("%s", d->name);
	printf("   ��������Ա������");
	scanf("%d", &d->score);
	printf("   ��������Ա���壺");
	scanf("%f", &d->rebound);
	printf("   ��������Ա���䣺");
	scanf("%d",&d->year);
	printf("   ��������Ա��ߣ�");
	scanf("%f",&d->high);
	system("cls");
	stu = head->next;
	int s;
	char ssname[20];
	printf("ͷ���밴1��β���밴2������ĳ����Ա�����밴3��\n");
	scanf("%d", &s);
	system("cls");
	switch (s)
	{
	case 1:
		d->next = stu;
		head->next = d;
		printf("ͷ��ɹ���\n");
		break;
	case 2:
		while (stu->next != NULL)
		{
			stu = stu->next;
		}
		stu->next = d;
		d->next = NULL;
		printf("β��ɹ���\n");
		break;
	case 3:
		printf("������Ҫ������һ����Ա֮��\n");
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
void deletee(struct nba* head)      //ɾ������
{
	struct nba* stu, * p1;
	stu = head->next;
	char s2name[20];
	printf("������Ҫɾ������Ա������\n");
	scanf("%s", s2name);
	if (stu != NULL)
	{
		if (!strcmp(s2name, stu->name))
		{
			p1->next = stu->next;
			printf("��Ա��ɾ����\n");
			return ;
		}
		p1 = stu;
		stu = stu->next;
	}else{
		printf("�����ڸ���Ա��\n");
	}
}
void filee(struct nba* stu)             //��д�ļ�����
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
	printf("�ļ�д��ɹ���\n");
	fclose(fp);
}
struct nba* du()                           //�����ļ� 
{
	n = 0;
	char fname[20],ch;
	struct nba* head, * p1, * p2;
	FILE *fp;
	fp = fopen("fi.txt", "r");	
	if(fp != NULL)
		printf("�򿪳ɹ���\n"); 	
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
	printf("�ļ���ȡ�ɹ���������%d����Ա", n);
	fflush(stdin);
	getchar();
	system("cls");
	return head;
}
void face()         //�ο� 
{
	printf("\n\n\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\t\t\t\t\t            |           1-��ʾ������Ա��Ϣ             |\n");
	printf("\t\t\t\t\t            |           2-��ѯ��Ա��Ϣ                 |\n");
	printf("\t\t\t\t\t            |           3-������˳�������Ա��Ϣ       |\n");
	printf("\t\t\t\t\t            |           4-��Ա��Ϣͳ��                 |\n");
	printf("\t\t\t\t\t            |           5-��Ա�Ա�                     |\n");
	printf("\t\t\t\t\t            |           6-�˳�                         |\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\n\n\n");
}
void face2()                                           //����Ա 
{
	printf("\n\n\n");
	printf("\t\t\t\t\t            ********************************************\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\n");
	printf("\t\t\t\t\t            --------------------------------------------\n");
	printf("\t\t\t\t\t            |           1-��ʾ������Ա��Ϣ             |\n");
	printf("\t\t\t\t\t            |           2-��ѯ��Ա��Ϣ                 |\n");
	printf("\t\t\t\t\t            |           3-�����ݶ��뵽�ļ�             |\n");
	printf("\t\t\t\t\t            |           4-�޸�ĳ����Ա��Ϣ             |\n");
	printf("\t\t\t\t\t            |           5-ɾ��ĳ����Ա��Ϣ             |\n");
	printf("\t\t\t\t\t            |           6-��������Ա��Ϣ               |\n");
	printf("\t\t\t\t\t            |           7-������˳�������Ա��Ϣ       |\n");
	printf("\t\t\t\t\t            |           8-��Ա��Ϣͳ��                 |\n");
	printf("\t\t\t\t\t            |           9-��Ա�Ա�                     |\n");
	printf("\t\t\t\t\t            |           10-�˳�                        |\n");
	printf("\t\t\t\t\t            ********************************************\n");

	printf("\n\n\n");
}
void face3()                //
{
	printf("\t\t\t\t\t******************************************\n");
	printf("\t\t\t\t\t------------------------------------------\n\n\n");
	printf("\t\t\t\t\t          1,�ֶ�¼����Ա��Ϣ              \n");
	printf("\t\t\t\t\t          2,�ļ�������Ա��Ϣ              \n\n\n");
	printf("\t\t\t\t\t------------------------------------------\n");
	printf("\t\t\t\t\t******************************************\n\n");
	printf("\t\t\t\t\t");
}
void face4()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t\t��ӭʹ��NBA����ϵͳ            \n\n\n\n");
}
void face5()       //��Ա 
{
	printf("\t\t\t\t\t******************************************\n");
	printf("\t\t\t\t\t------------------------------------------\n\n\n");
	printf("\t\t\t\t\t          1,��ʾ������Ա��Ϣ              \n");
	printf("\t\t\t\t\t          2,��ѯ��Ա��Ϣ                  \n");
	printf("\t\t\t\t\t          3,������˳�������Ա��Ϣ        \n");
	printf("\t\t\t\t\t          4,��Ա�Ա�                      \n");
	printf("\t\t\t\t\t          5,�޸��Լ�����Ϣ              \n");
	printf("\t\t\t\t\t          6,�˳�                          \n");
	printf("\t\t\t\t\t******************************************\n");
} 
void face6()           //��¼ 
{	
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************************\n\n");
	printf("\t\t\t\t\t                     ��¼                      \n");
	printf("\t\t\t\t\t                 1,����Ա��¼                 \n");
	printf("\t\t\t\t\t                 2,��Ա��¼                   \n");
	printf("\t\t\t\t\t                 3,�ο͵�¼                   \n");
	printf("\t\t\t\t\t                 4,ע�ᣨֻ����Ա�ſ���ע�ᣩ \n"); 
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
			case 1://1-��ʾ������Ա��Ϣ
				print(head);
				break;
			case 2://2-��ѯ��Ա��Ϣ
				query(head);
				break;
			case 3://3-������˳�������Ա��Ϣ
				sort(head);
				break;
			case 4:
				print2(head);
				break;
			case 5://5-��Ա�Ա�
				compare(head);
				break;
			case 6://10-�˳�
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
			case 2://2-��ѯ��Ա��Ϣ
				query(head);
				break;
			case 3://3,������˳�������Ա��Ϣ
				sort(head);
				break;
			case 4://4,��Ա�Ա�
				compare(head);
				break;
			case 5://5,�޸��Լ�����Ϣ
			case 6:	//10-�˳�
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
			case 1://1-��ʾ������Ա��Ϣ
				print(head);
				break;
			case 2://2-��ѯ��Ա��Ϣ
				query(head);
				break;
			case 3://3-�����ݶ��뵽�ļ�
				filee(head);
				break;
			case 4://4-�޸�ĳ����Ա��Ϣ
				modify(head);
				break;
			case 5://5-ɾ��ĳ����Ա��Ϣ
				deletee(head);
				break;
			case 6://6-��������Ա��Ϣ
				insert(head);
				break;
			case 7://7-������˳�������Ա��Ϣ
				sort(head);
				break;
			case 8://8-��Ա��Ϣ��ʽ�����
				print2(head);
				break; 
			case 9://9-��Ա�Ա�
				compare(head);
				break;
			case 10://10-�˳�
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
