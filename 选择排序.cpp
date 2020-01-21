#include<stdio.h>
void fun(){
		int a[10],i; 
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int j,k;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[j]>a[i])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;		
			}
		}
	}
	for(i=0;i<10;i++)
	{
	printf("%d   ",a[i]);
	}
}
int main(){
	fun();
return 0;
}
