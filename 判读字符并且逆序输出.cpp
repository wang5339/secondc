#include<stdio.h>
#include<string.h>
char *str(char*s,char x){
	 int c=0;
	 while(s[c]!=x&&s[c]!='\0'){
	 	c++;
	 }
	 return (&s[c]);
}
int main(){
	char s[40],*p,x;
	gets(s);
	x=getchar();
	p=str(s,x);
	if(*p){
		printf("%c",*p);
		while(p-s){
			p--;
			printf("%c",*p);
		}
	}else{
		printf("%c",x);
	}
	return 0;

}
