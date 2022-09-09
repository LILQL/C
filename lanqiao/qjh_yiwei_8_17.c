#include<stdio.h>
#include<stdlib.h>

#define N 100010

int sum[N];
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum[i]=x+sum[i-1];
    }
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d",sum[r]-sum[l-1]);
    }
    return 0;
}

