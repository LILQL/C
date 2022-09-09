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
    int a, b, t;
    for (a = 0; a < N - 1; a++)
    {
        for (b = 0; b < N - 1 - a; b++)
        {
            if (S[0] < S[b])
            {
                if (b < MAXN)
                {
                    t = S[0];
                    S[0] = S[b];
                    S[b] = S[0];
                }
                else
                {
                    break;
                }
            }
        }
    }
    return S[0];
}

/* 你的代码将被嵌在这里 */
