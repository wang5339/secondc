#include <stdio.h>
int main() {
	char c;
	int l = 0, s = 0, d = 0, o = 0;
	printf("������һ���ַ���");
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
	printf("��ĸ��:%d\n�ո���:%d\n������:%d\n�����ַ�:%d\n", l, s, d, o);
	return 0;
}
