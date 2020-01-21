#include<stdio.h>
#include<stdlib.h>
int main() {
	char a, b, c ;
	char i;
	for (i = 'x'; i <= 'z'; i++) {
		if (i != 'x' && i != 'z') {
			c = i;
		}
	}
	for (i = 'x'; i <= 'z'; i++) {
		if (i != 'x' && i != c) {
			a = i;
		}
	}
	for (i = 'x'; i <= 'z'; i++) {
		if (i != a && i != c) {
			b = i;
		}
	}
	printf("a-%c,b-%c,c-%c", a, b, c);
	return 0;
}
