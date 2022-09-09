#include <stdio.h>
#include <stdlib.h>
#define N 400
int s = 0;
int main()
{
    for (int x1 = 0; x1 < 20; x1++)
    {
        for (int y1 = 0; y1 < 21; y1++)
        {
            for (int x2 = 0; x2 < 20; x2++)
            {
                for (int y2 = 0; y2 < 21; y2++)
                {
                    if (x1 != x2)
                    {
                        double k = (double)(y2 - y1) / (x2 - x1);
                        double b = y1 - k * x1;
                    }
                }
            }
        }
    }
    printf("%d", s);
    system("pause");
    return 0;
}