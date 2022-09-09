#include <stdio.h>
#include <stdlib.h>

int Count_Digit(const int N, const int D);

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    system("pause");
    return 0;
}

int Count_Digit(const int N, const int D)
{
    int i, a[10] = {0}, n = 0, t = 0;
    if (N < 0)
    {
        n = -N;
    }
    else if (N == 0)
    {
        return 1;
    }
    else
    {
        n = N;
    }
    while (n > 0)
    {
        for (i = 0; i < 10; i++) /*i从0~9，若被判断数中有与i相同的数执行a[i]+=1*/
        {
            if (n % 10 == i) /*取位数*/
            {
                a[i] += 1;
            }
        }
        n = n / 10; /*取位数*/
    }
    t = a[D];
    return t;
}

/* 你的代码将被嵌在这里 */
