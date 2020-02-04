#include <stdio.h>
int main(){
	int x,y,z;
	for (x = 1; x <= 100; x++)
		for (y=1; y <= 50; y++)
			for (z = 1; z<=20; z++)
				if (x+2 * y+5 *z == 100)
				{
					printf("%d+2*%d+5*%d=100\n", x,y,x);
				}
	return 0;
}
