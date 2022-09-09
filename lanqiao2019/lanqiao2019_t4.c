#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int ans = 0;
    for (int x = 1; x < 2019; x++)
    {
        for (int y = 1; y < 2019; y++)
        {
            if (x == y)
                continue;
            int z = 2019 - x - y;
            if (z <= 0)
                continue;
            if (x == z || y == z)
                continue;
            if (check(x, y, z) && (2019 == x + y + z))
            {
                ans++;
            }
        }
    }
    printf("%d", ans / 6);
    system("pause");
    return 0;
}

int check(int a, int b, int c)
{
    while (a)
    {
        int t;
        t = a % 10;
        if (t == 2 || t == 4)
        {
            return 0;
            break;
        }
        a /= 10;
    }
    while (b)
    {
        int t;
        t = b % 10;
        if (t == 2 || t == 4)
        {
            return 0;
        }
        b /= 10;
    }
    while (c)
    {
        int t;
        t = c % 10;
        if (t == 2 || t == 4)
        {
            return 0;
        }
        c /= 10;
    }
    return 1;
}