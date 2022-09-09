#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[110];
char b[10010];
int main()
{
    scanf("%s", a);
    int l = strlen(a);
    int s;
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        if (a[i] > '9') //是字母
        {
            if (a[i + 1] >= '0' && a[i + 1] <= '9') //下一位是数字
            {
                s = a[i + 1] - '0';
                for (int j = 0; j < s; j++)
                {
                    b[k++] = a[i];
                }
            }
            else //下一位是字母
            {
                b[k++] = a[i];
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}