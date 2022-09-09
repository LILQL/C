#include <stdio.h>
#include <stdlib.h>
int stn[15];//1为选择，2为不选，0为没选。
int n;
void dfs(int u)
{   
    //边界
    if(u>n)
    {
        for(int i=1; i<=n;i++)
        {
            if(stn[i]==1)
            {
                printf("%d",i);
            }
        }
        printf("\n");
        return 0;
    }

    //问题（分支）
    stn[u]=2;
    dfs(u+1);
    stn[u]=0;

    stn[u]=1;
    dfs(u+1);
    stn[u]=0;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    system("pause");
    return 0;
}