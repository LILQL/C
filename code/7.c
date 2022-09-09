#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))
            cnt++;
    }
    printf("cnt = %d\n", cnt);
    system("pause");
    return 0;
}

int IsTheNumber(const int N)
{
    int a, b;
    a = (int)sqrt(N); /*强制取余再平方，与原数比较 */
    b = a * a;
    if (b == N)
    {
        int i, a[10] = {0};
        while (b > 0)
        {
            for (i = 0; i < 10; i++) /*i从0~9，若被判断数中有与i相同的数执行a[i]+=1*/
            {
                if (b % 10 == i) /*取位数*/
                {
                    a[i] += 1;
                    if (a[i] == 2) /*若a[i]==2，说明有两位数的值相同，满足返回1（执行）*/
                    {
                        return 1;
                    }
                }
            }
            b = b / 10; /*取位数*/
        }
    }
    return 0;
}