#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main()
{
	int i, sum = 0;
	char a[20];
	gets(a);
	for (i = 0; i < 20; i++) {
		if (a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9' || a[i] == '0' || a[i] == '*' || a[i] == '#') {
			sum += 1;
		}
		if (a[i] == 'a' || a[i] == 'd' || a[i] == 'g' || a[i] == 'j' || a[i] == 'm' || a[i] == 'p' || a[i] == 't' || a[i] == 'w' || a[i] == ' ') {
			sum += 2;
		}
		if (a[i] == 'b' || a[i] == 'e' || a[i] == 'h' || a[i] == 'k' || a[i] == 'n' || a[i] == 'q' || a[i] == 'u' || a[i] == 'x') {
			sum += 3;
		}
		if (a[i] == 'c' || a[i] == 'f' || a[i] == 'i' || a[i] == 'l' || a[i] == 'o' || a[i] == 'r' || a[i] == 'v' || a[i] == 'y') {
			sum += 4;
		}
		if (a[i] == 'z' || a[i] == 's') {
			sum += 5;
		}
	}
	printf("%d", sum);
	return 0;
}
