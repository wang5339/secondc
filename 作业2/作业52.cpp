#include <stdio.h>
int main(){
    unsigned a, b, c, d;
    printf("ÇëÊäÈëÕûÊý£º\n");
    scanf("%o", &a);
    b = a >> 4;
    c = ~(~0 << 4);
    d = b & c;
    printf("%o\n%o", a, d);
    return 0;
}
