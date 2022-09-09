#include <stdio.h>
#include <stdlib.h>

void PrintN(int N);

int main()
{
    int N;

    scanf("%d", &N);
    PrintN(N);
    system("pause");
    return 0;
}

void PrintN(int N)
{
    int a;
    for (a = 1; a <= N; a++)
    {
        printf("%d\n", a);
    }
}