#include<stdio.h>
int main(){
int c,m,n,i,j;
int t=0;
int a[20][20];
scanf("%d%d",&m,&n);
if(m>n)
c=n/2+1;
else
c=m/2+1;
for(i=0;i<c;i++)
{
for(/*j=0*/j=i;j<n-i-1;j++)
{
t++;
a[i][j]=t;
}
for(j=i;j<m-i-1;j++)
{
t++;
a[j][n-i-1]=t;
}
for(j=n-i-1;j>i;j--)
{
t++;
a[m-i-1][j]=t;
}
for(j=m-i-1;j>i;j--)
{
t++;
a[j][i]=t;
}
}

for(i=0;i<m;i++)
for(j=0;j<n;j++)
{
printf("%4d ", a[i][j]);
if(((j+1)%n) == 0)
printf("\n");
}
}
