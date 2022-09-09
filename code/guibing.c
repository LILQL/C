#include <stdio.h>
#include <stdlib.h>
#define max 10

int guibing(int a[10], int n);
int zonghe(int left_size, int *left, int right_size, int *right);
int main()
{
    int a[10], i;
    for (i = 0; i <= 9; i++)
    {
        scanf("%d", &a[i]);
    }
    guibing(a, 10);
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }

    system("pause");
    return 0;
}

int guibing(int a[10], int n)
{
    if (n > 1)
    {
        int final[10];
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
    int temp[max];
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