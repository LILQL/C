#include <stdio.h>
#include <stdlib.h>
int charu(int a[10]);

int main()
{
    int a[10], i;
    for (i = 0; i <= 9; i++)
    {
        scanf("%d", &a[i]);
    }
    charu(a);
    for (i = 9; i >= 0; i--)
    {
        printf("%d\t", a[i]);
    }

    system("pause");
    return 0;
}

int charu(int a[])
{
    for (int i = 1; i <= 9; i++)
    {
        int j, temp;
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            for (j = i - 1; temp < a[j] && j >= 0; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp; /*在j处停住，覆盖j+1的重复值*/
        }
    }
}