#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){ 
	long int i,x,y;   
	for(i = 0;i <= 100000;++i)    {    
		x = sqrt(i+100);   
		y = sqrt(i+268);
		if((x*x == i + 100)&&(y*y == i+268))  
			printf("%ld\t",i);  
	}
	return 0;
}

