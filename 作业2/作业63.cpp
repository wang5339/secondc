#include<stdio.h>
int main(){
	int i,a[100],m,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	scanf("%d",&m);
	int c=n+1;
	for(i=1;i<=m;i++){
		a[c]=a[i];
		c++;
	}
	for(i=m+1;i<=m+n;i++){
		printf("%d   ",a[i]);	
	}

	return 0;
} 
