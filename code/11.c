#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cm = 0, foot = 0, inch = 0;
    scanf("%d", &cm);
    foot = cm / (100 * 0.3048);
    inch = (cm / (100 * 0.3048) - foot) * 12;
    printf("%d %d", foot, inch);
    system("pause");
    return 0;
}
