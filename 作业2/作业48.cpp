#include <stdio.h>
void s(int* pa, int* pb)
{
    int t;
    t = *pa;
    *pa = *pb;
    *pb = t;
}
int main()
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("\nb = ");
    scanf("%d", &b);
    s(&a, &b);
    printf(" %d \n %d\n", a, b);
    return 0; 
}

