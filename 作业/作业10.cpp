#include <stdio.h>
#include <time.h>
#include <windows.h>
int main(){
    time_t rawtime;
    struct tm *timeinfo;
    char timE[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timE, 80, "%b %d, %Y  %H:%M:%S",timeinfo);
    printf("��ǰʱ���ǣ�");
    printf("%s\n", timE);
    Sleep(1000);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timE, 80, "%b %d, %Y  %H:%M:%S",timeinfo);
    printf("��ǰʱ���ǣ�");
    printf("%s\n", timE);
    return 0;
}
