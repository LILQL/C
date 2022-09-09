#include <stdio.h>
#include <stdlib.h>
int s[10];
int check(int x);
int main()
{
    for (int i = 0; i < 10; i++)
        s[i] = 2021;
    for (int j = 1;; j++)
    {
        if (check(j))
        {
            printf("%d", j - 1);
            break;
        }
    }
    system("pause");
    return 0;
}

int check(int x)
{
    int t;
    while (x)
    {
        t = x % 10;
        x /= 10;
        if (--s[t] < 0)
        {
            return 1;
        }
    }
    return 0;
}