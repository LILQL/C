#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[40][40];
    int i = 1, j = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    f[1][1] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            if (i % 2 || j % 2)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1]; 
            }
        }
    }
    printf("%d", f[n][m]);
    system("pause");

    return 0;
}