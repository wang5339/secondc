#include<stdio.h>
void han(int *b) {
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (b[i] == b[j]) {
				printf("true");
				return;
			}
		}
	}
	printf("false");
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,9 };
	han(a);
	return 0;
}


