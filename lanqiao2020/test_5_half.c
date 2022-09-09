#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[10], key, ars;
    int len = 10;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, 10);
    printf("test\n");
    for (int j = 0; j < 10; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\n");
    printf("enterkey\n");
    scanf("%d", &key);
    ars = half(a, len, key);
    printf("%d", ars);
    system("pause");
    return 0;
}

int half(int a[], int len, int key)
{
    int L = 1;
    int R = len;
    int mid;
    int ars = 0;
    while (L <= R)
    {
        mid = (L + R) / 2;
        if (a[mid] == key)
        {
            ars = mid;
            break;
        }
        if (a[mid] > key)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }

    return ars;
}

int sort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            int temp;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}