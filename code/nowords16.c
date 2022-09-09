#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", n);
    no(n);
    system("paose");
    return 0;
}

int no(int n)
{

    int a[10];
    int b[10];
    int j = 0;
    To_Hex(n, a);
    for (int i = 0; i < 10; i++)
    {
        if ((a[i] >= "a") && (a[i] <= "z"))
        {
            break;
        }
        else
        {
            for (j = 0; j < 10; j++)
            {
                b[j] = a[i];
            }
        }
    }
    for (int m = 0; m < 10; m++)
    {
        printf("%d", b[m]);
    }
}

void To_Hex(unsigned int value, char buffer[])
{
    unsigned int i = (sizeof(unsigned int) * 2);
    unsigned int temp;
    int j = 0;
    while (i--)
    {
        temp = (value & (0xf << (4 * i))) >> (4 * i);
        if (temp > 9)
            buffer[j] = 'A' + temp - 10;
        else
            buffer[j] = '0' + temp;
        j++;
    }
    return buffer;
}