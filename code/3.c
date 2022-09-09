#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

int Sum(int List[], int N);

int main()
{
    int List[MAXN], N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));
    system("pause");

    return 0;
}

int Sum(int List[], int N)
{
    int i, sum;
    for (i = 0; i < N; i++)
    {
        sum += List[i];
    }
    return sum;
}
