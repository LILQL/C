#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main()
{

    typedef struct LNode *List;
    struct LNode
    {
        int Data[MAX];
        int last;
    };
    struct LNode L;
    List PtrL;
    printf("%d\n", L.Data[0]);
    printf("%d", PtrL->Data[0]);
    system("pause");
    return 0;
}