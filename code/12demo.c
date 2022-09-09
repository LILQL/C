#include <stdio.h>
#include <stdlib.h>
int main()
{
    int start = 0, pass1 = 0, pass2 = 0, hours = 0, a[3], b[3], now = 0;
    scanf("%d%d", &start, &pass1);
    /*将分存入a[0]*/
    a[0] = start % 100;
    start / 100;

    a[1] = start; /*将时存入a[1]*/
    while (pass1 >= 60)
    {
        pass1 -= 60;
        hours++;
    }
    b[0] = pass1;
    b[1] = hours * 100;
    now = b[0] + b[1];
    printf("%d", &now);
    system("pause");
    return 0;
}