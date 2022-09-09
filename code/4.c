#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
typedef float ElementType;

ElementType Average(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));
    system("pause");

    return 0;
}

ElementType Average(ElementType S[], int N)
{
    ElementType sum = 0, a;
    int i;
    for (i = 0; i < N; i++)
    {
        sum += S[i];
    }
    a = sum / N;
    return a;
}

/* 你的代码将被嵌在这里 */
