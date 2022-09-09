#include <stdio.h>
#include <stdlib.h>

int Factorial(const int N);

int main()
{
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)
        printf("%d! = %d\n", N, NF);
    else
        printf("Invalid input\n");

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
int Factorial(const int N)
{
    int i, t = 1, n;
    if (N < 0)
    {
        n = -N;
    }
    else
    {
        n = N;
    }
    if (n <= 12)
    {
        for (i = 1; i <= n; i++)
        {
            t = t * i;
        }
        return t;
    }
    else
    {
        return 0;
    }
}