#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int are = 0;
int main()
{
    int a[100];
    int n;
    printf("?????????????\n");
    scanf("%d", &n);
    printf("???????????????");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    BubbleSort(a, n);
    greedy(n, a);
    printf("????????:\n");
    printf("%d", are);
    system("pause");

    return 0;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void BubbleSort(int k[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (k[i] > k[j])
            {
                temp = k[j];
                k[j] = k[i];
                k[i] = temp;
            }
        }
    }
}

int greedy(int laft, int a[])
{
    int s1, s2;
    while (laft > 0)
    {
        if (laft == 1)
        {
            are += a[0];
            break;
        }
        else if (laft == 2)
        {
            are += a[1];
            break;
        }
        else if (laft == 3)
        {
            are += a[0] + a[1] + a[2];
            break;
        }
        else
        {
            /*?????????????????*/
            s1 = (2 * a[0]) + a[laft - 2] + a[laft - 1]; /*???????????????????????????*/
            s2 = (2 * a[1]) + a[laft - 1] + a[0];
            are += min(s1, s2);
        }
        laft -= 2;
    }
}