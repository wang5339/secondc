#include<stdio.h>
#include<string.h>
struct person{
	char name[20];
	int count;
}leader[3]={"li",0,"zhang",0,"wang",0};
int main() {
	int i,j;
	char leader_name[20];
	printf("输入10个的票人的姓氏（li,zhang,wang）:\n");
    for(i=1;i<=5;i++){
    	scanf("%s",leader_name);
    	for(j=0;j<3;j++){
    		if(strcmp(leader_name,leader[j].name)==0){
    			leader[j].count++;
			}
		}
	}
	for(i=0;i<3;i++){
		printf("%s:%d\n",leader[i].name,leader[i].count);	
	}
	return 0;
}
