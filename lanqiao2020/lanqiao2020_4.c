#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int s[11][N];
int main()
{
    int n = 0, m = 0, K = 0;
    int a[100];
    scanf("%d%d", &n, &m);
    scanf("%d", &K);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // hash
    for (int i = 0; i < n; i++)
    {
        int t = a[i] % m;
        for (int j = 0; j < 11; j++)
        {
            s[j][t]++;
            t = (t * 10) % m;
        }
    }
    // main
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = a[i] % m;
        int len = strlen(a[i]);
        res += s[len][(m - t) % m];

        int r = t;
        while (len--)
            r = r * 10 % m;
        if (r == (m - t) % m)
            res--;
    }

    printf("%d", res);

    return 0;
}