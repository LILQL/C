#include<stdio.h>
#include<stdlib.h>
#define N 10
int st[N];//0——表示没有数，1--n——表示对应的数
int used[N];//判对应数字是否被使用过
int n;

void dfs(int u)
{
    if(u>n)//边界
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",st[i]);
        }
        printf("\n");
        return;
    }
    //分支
    for (int i=1;i<=n;i++)//遍历这个位置可以用那些数
    {
        if(!used[i])
        {
            st[u]=i;
            used[i]=1;
            dfs(u+1);
            //恢复状态
            st[u]=0;
            used[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    system("pause");
    return 0;
}