#include<stdio.h>
int a[101],n;
void fun(int left,int right){
	int t,i,j,temp;
	if(left>right)
	{
		return ;
	}
	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
		{
			j--;
		}
		while(a[i]<=temp&&i<j)
		{
			i++;
		}
		if(i<j)
		{
		 t=a[i];
		 a[i]=a[j];
		 a[j]=t;
		 }
	}
	a[left]=a[i];
	a[i]=temp;
	fun(left,i-1);
	fun(i+1,right);
	return;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	fun(1,n);
	for(i=1;i<=n;i++){
		printf("%d    ",a[i]);
	}
	return 0;

}


