#include <stdio.h>
int main(){
	char i, j;
	printf("������Сд����ĸ��");
	scanf("%c", &i);
	getchar();
	switch(i)
	{
		case 'm':
			printf("Monday\n");
			break;
		case 'w':
			printf("Wednesday\n");
			break;
		case 'f':
			printf("Friday\n");
			break;
		case 't':
			printf("��������һ��Сд��ĸ��");
			scanf("%c", &j);
			if (j == 'u')
				printf("Tuesday\n");
			else if (j == 'h')
				printf("Thursday\n");
			else
				printf("Error!\n");
			break;
		case 's':
			printf("��������һ��Сд��ĸ��");
			scanf("%c", &j);
			if (j == 'a')
				printf("Saturday\n");
			else if (j == 'u')
				printf("Sunday\n");
			else
				printf("Error!\n");
			break;
	}
	return 0;
}
