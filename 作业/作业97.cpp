#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}node;
typedef node *link;

int main(void)
{
    link p, head, tail;
    int num, i;
    tail = (link)malloc(sizeof(node));
    tail->next = NULL;
    p = tail;
    printf("������5��������");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &num);
        p->data = num;
        head = (link)malloc(sizeof(node));
        head->next = p;
        p = head;
    }
    p = p->next;
    printf("��ת�������Ϊ��");
    while(p != NULL)
    {
        printf("%-3d", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
