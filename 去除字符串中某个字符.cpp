#include<stdio.h>
#include<string.h>
void fun(char d[], char f) {
	int i = 0, k = 0;
	while (d[i] != '\0') {
		if (d[i] != f) {
			d[k++] = d[i];
		}
		i++;
	}
	d[k] = '\0';
}
int main() {
	char str[] = "how,are,you!aaaaabbbcc", * p = str, c = 'a';
	printf("%s\n", str);
	fun(p, c);
	printf("%s\n", str);
	return 0;
}

