#include<stdio.h>
int a[101],b[101],c[101];
int main(){
    int i=0,n=1,x,y=1,z=0,q=0,w;
   scanf("%d",&i);
   while(i!=-1){
      a[n]=i;
	  n++; 
	  scanf("%d",&i); 	
   }
 //  for(w=1;w<n;w++){
   
   //printf("%d",a[w]);}
   scanf("%d",&x);
   while(x!=-1){
   	b[y]=x;
   	y++;
   	scanf("%d",&x);

   }
    //  for(w=1;w<y;w++){
   
 // printf("%d  %d",n,y);
  	 // for(w=1;w<=y;w++){
   
   //printf("%d",a[w]);}
   n--;
   y--;
 if(n>=y)
   {
   	for(;n!=0;n--)
	   {
   		if(y!=0){
   	    c[z]=a[n]+b[y];
   	       z++;
		   y--;	
		   }else{
		   	c[z]=a[n];
		   	z++;
		   }
		}
		for(q=0;q<z;q++){
		
		printf("%d",c[q]);}}
	/*	for(q=0;q<=z-1;q++){
			if(c[q]>=10){
				c[q]=c[q]-10;
				c[q+1]++;
			}
		}
		for(q=0;q<=z-1;q++){
			printf("%d",c[q]);
		}
		
   }
/*   for
   if(y>n)
   {
   	for(;y!=0;y--)
	   {
   		if(n!=0){
   	b[y]=a[n]+b[y];
		   n--;	
		   }else{
		   	b[y]=b[y];
		   }
		}
   }
   
  // for(x=1;x<n;x++)
   //printf("%d",a[x]);
	
   
*/
return 0;	
}
