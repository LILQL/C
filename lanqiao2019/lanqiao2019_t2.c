#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    int k = 0;
    char ans[100] = " ";
    scanf("%d", &n);
    while (n)
    {
        if (n % 26 == 0)
        {
            ans[k++] = 'Z';
        }
        else
        {
            ans[k++] = 'A' + n % 26 - 1;
        }
        n--;
        n /= 26;
    }
    for (int i = strlen(ans) - 1; i >= 0; i--)
        printf("%c", ans[i]);
    system("pause");
    return 0;
}