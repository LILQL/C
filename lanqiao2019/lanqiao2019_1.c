#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(int t1);
int main()
{
    int a[10000];
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        int t1 = a[j];
        if (check(a[j]))
        {
            ans += a[j];
        }
    }
    printf("%d", ans);
    system("pause");
    return 0;
}

int check(int t1)
{
    while (t1)
    {
        int t2 = t1 % 10;
        if (t2 == 2 || t2 == 0 || t2 == 1 || t2 == 9)
        {
            return 1;
        }
        t1 /= 10;
    }
    return 0;
}