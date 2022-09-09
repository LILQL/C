#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
typedef float ElementType;

ElementType Max(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));
    system("pause");
    return 0;
}

ElementType Max(ElementType S[], int N)
{
    int a, max = 0;
    for (a = max; a < N; a++)
    {
        if (S[max] < S[a])
        {
            max = a;
        }
    }
    return S[max];
}