#include <stdio.h>
#include <stdlib.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial(const int N)
{
    int i, j = 0, alength = 1; /*alength为得数的长度*/
    char a[3000];
    a[0] = 1;
    if (N < 0)
    {
        printf("Invalid input\n");
        return;
    }
    else
    {
        for (i = 2; i <= N; i++)
        {
            int k, z = 0;
            for (k = 0; k < alength; k++)
            {
                int t = 0;        /*工具变量*/
                t = i * a[k] + z; /*z为进位数，a[k]为进位数的上一位(打印数)*/
                a[k] = t % 10;
                z = t / 10;
            }
            while (z) /*判断进位数是否存在*/
            {
                a[alength++] = z % 10; /*存与后一位*/
                z = z / 10;            /*再清零*/
            }
        }
        for (j = alength - 1; j >= 0; j--)
        {
            printf("%d", a[j]);
        }
    }

    printf("\n");
}