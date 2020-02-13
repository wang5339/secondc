#include <stdio.h>
int main() {
	char c;
	int l = 0, s = 0, d = 0, o = 0;
	printf("请输入一行字符：");
	while ((c = getchar()) != '\n') {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			l++;
		}
		else if (c == ' ') {
			s++;
		}
		else if (c >= '0' && c <= '9') {
			d++;
		}
		else {
			o++;

		}
	}
	printf("字母数:%d\n空格数:%d\n数字数:%d\n其他字符:%d\n", l, s, d, o);
	return 0;
}
