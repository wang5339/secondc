 #include<stdio.h>
 #include<string.h>
 int main(){
 	int a[3][3]={1,8,3,4,5,6,7,8,9};
	int *pa[3];
 	int b[3]={12,34,56};
 	pa[0] = a[0];
 	pa[1]=a[1];
 	pa[2]=a[2];
	printf("%d\n",*(*(pa+1)+2));
// 	printf("%d",*(*(a+1)+2));
  	printf("%d\n",*(a[0]+2));
  	printf("%d\n",*(a[0]+1));
  	printf("%d\n",*(*(pa+2)+2));
  	printf("%d",*(pa[0]+2));
 }

