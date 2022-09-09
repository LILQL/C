#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int table[100];
int main()
{
    int a[10];
    int b[100];
    int len = strlen(a);
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    create_hash(a, len);
    for (int i = 0; i < strlen(table); i++)
    {
        printf("%d", table[i]);
    }
    sort(b, table, strlen(table));
    for (int i = 0; i < strlen(b); i++)
    {
        printf("%d", b[i]);
    }

    system("pause");

    return 0;
}

void create_hash(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        table[a[i]]++;
    }
}
void sort(int b[], int t[], int len)
{
    int j;
    for (int i = 0; i < len; i++)
    {
        while (t[i]--)
        {
            b[j++] = i;
        }
    }
}