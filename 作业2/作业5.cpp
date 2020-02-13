#include<stdio.h>
int min(int a,int b){
	return a>b?b:a;
	}
int max(int a,int b){
	return a>b?a:b;} 
int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);	
	printf(" %d  %d  %d\n", min(min(x,y),z), (x>min(min(x,y),z) && x<max(max(x,y),z)) ? x : y>min(min(x,y),z) && y<max(max(x,y),z) ? y : z, max(max(x,y),z));} 
//2,#include<stdio.h>
//int main(){
//	int x,y,z,t;
//	scanf("%d,%d,%d",&x,&y,&z);	
//	if(x>y){	
//		t=x;	
//		x=y;
//		y=t;
//	}	
//	if(x>z){		
//		t=x;	
//		x=z;
//		z=t;	
//	}	
//	if(y>z){		
//	t=y;	
//	y=z;		
//	z=t;	
//	}	
//	printf(" %d  %d  %d\n",x,y,z);}
//3,#include<iostream>
//using namespace std;
//void main()
//{
//int x,y,z;
//cin>>x>>y>>z;
//x<y?(x<z?x:(z^=x,x^=z,z^=x)):(y<z?(x^=y,y^=x,x^=y):(x^=z,z^=x,x^=z));
//cout<<x<<"     "<<y<<"     "<<z<<"     "<<endl;
//system("pause");
//}
//4,#include <stdio.h>
//void swap(int *s1, int *s2)
//{
//    int t = *s1;
//	*s1 = *s2;
//	*s2 = t;
//}
//int main()
//{
//    int a, b, c;
//    int *p1, *p2, *p3;
//    scanf("%d %d %d", &a, &b, &c);
//    p1 = &a;
//    p2 = &b;
//    p3 = &c;
//    if (a > b)
//        swap(p1, p2);
//    if (a > c)
//        swap(p1, p3);
//    if (b > c)
//        swap(p2, p3);
//    printf("从小到大的顺序为：%d %d %d\n", a, b, c);
//    return 0;
//}

