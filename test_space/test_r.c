#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int a[100];
    a[0]=1;
    a[1]=1;
    printf("please enter:\n");
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    printf("%d",a[n]);
    system("pause");
    return 0;
}