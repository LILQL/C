#include <stdio.h>
#include <stdlib.h>

int select(int a[10]);

int main()
{
    int a[10], i;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    select(a);
    for (i = 9; i >= 0; i--)
    {
        printf("%d\t", a[i]);
    }

    system("pause");
    return 0;
}

int select(int a[])
{
    int temp, min;
    for (int i = 0; i < 9; i++)
    {
        min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (a[j] < a[min])
            {
                min = j; /*换标签是为了防止有更小的数出现，因为直接换值时间效率低*/
            }
            if (min != i)
            {
                temp = a[j];
                a[j] = a[min];
                a[min] = temp;
            }
        }
    }
}
