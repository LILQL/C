#include <stdio.h>
#include <stdlib.h>
int bubble(int a[10]);
int selection(int a[10]);
int charu(int a[10]);
int guibing(int a[10], int n);
int zonghe(int left_size, int *left, int right_size, int *right);

int main()
{
    int a[10], j;
    int made;
    printf("从0-3选择模式\n");
    scanf("%d", &made);
    printf("输入十个数\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    if (made == 0)
    {
        bubble(a);
    }

    if (made == 1)
    {
        selection(a);
    }

    if (made == 2)
    {
        charu(a);
    }

    if (made == 3)
    {
        guibing(a, 10);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    system("pause");
    return 0;
}

int bubble(int *a)
{
    printf("冒泡法");
    int size = 10;
    for (int i = 0; i < size - 1; i++)
    {
        int temp;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int selection(int *a)
{
    for (int i = 0; i < 10; i++)
    {
        int min = 0, temp = 0;
        for (int j = i + 1; j < 10 && j > 0; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
            temp = a[min];
            a[min] = a[j];
            a[j] = temp;
        }
    }
}

int charu(int *a)
{
    for (int i = 1; i < 10; i++)
    {
        if (a[i] < a[i - 1])
        {
            int j, temp = a[i];
            for (j = i - 1; temp < a[j]; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

int guibing(int *a, int n)
{
    if (n > 1)
    {
        int left_size = n / 2;
        int *left = a;
        int right_size = n - left_size;
        int *right = a + n / 2;

        guibing(left, left_size);
        guibing(right, right_size);

        zonghe(left_size, left, right_size, right);
    }
}

int zonghe(int left_size, int *left, int right_size, int *right)
{
    int i, j, k;
    int temp[10];
    i = j = k = 0;
    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            temp[k++] = left[i++];
        }
        else
        {
            temp[k++] = right[j++];
        }
    }
    while (i < left_size)
    {
        temp[k++] = left[i++];
    }
    while (j < right_size)
    {
        temp[k++] = right[j++];
    }
    for (int m = 0; m < (left_size + right_size); m++)
    {
        left[m] = temp[m];
    }
}