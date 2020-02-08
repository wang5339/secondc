#include <stdio.h>
int main(){
    int a[10],i,max,maxp,min,minp,t;
    printf("ÇëÊäÈëÊı×é");
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    max=min=a[0];
    maxp=minp=0;
    for(i=1;i<10;i++)
    {
        if(a[i]>max)
        {
        max=a[i];
        maxp=i;
        }
           if(a[i]<min)
        {
        min=a[i];
        minp=i;
        }
}
if(minp!=0)
{
        t=a[0];
        a[0]=a[maxp];
           a[maxp]=t;
        t=a[9];
        a[9]=a[minp];
        a[minp]=t;
}
    else
{
t=a[0];
        a[0]=a[maxp];
           a[maxp]=t;
        t=a[9];
        a[9]=a[maxp];
        a[maxp]=t;
}

for(i=0;i<10;i++)
{
if(i!=4)
printf("%8d",a[i]);
else printf("%8d\n",a[i]);
}
printf("\n");
}
