#include <stdio.h>
#include <stdlib.h>

int digui(int n);
int main()
{
    int n;
    scanf("%d", &n);
    digui(n);
    system("pause");
    return 0;
}

int digui(int n)
{
    if (n > 0)
    {
        printf("%d", n % 10);
        digui(n / 10);
    }

    return n;
}
