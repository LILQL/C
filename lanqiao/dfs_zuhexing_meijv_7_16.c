#include<stdio.h>
#include<stdlib.h>
#define N 30
int st[N];
int n,m;

int dfs(int u , int start)
{
    if(u+n-start<m) return 0;
    if(u>m)
    {
        for (int i=1;i<=m;i++){
            printf("%d",st[i]);
        }
        printf("\n");
        return 0 ;
    }
    for (int i=start;i<=n;i++)
    {
        st[u]=i;
        dfs(u+1,i+1);
        st[u]=0;
    
    }

}

int main()
{
    scanf("%d%d",&n,&m);
    dfs(1,1);
    system("pause");
    return 0;
}