#include<stdio.h>
#include<stdlib.h>

int dfs(int m,int p,int q)
{
    if (!m) return 1;

    if(m>=p&&dfs(m-p,p,q)) return 1;

    if(m>=q&&dfs(m-q,p,q)) return 1;

    return 0;
}

int main(){

    while(1){
        int p,q,res;

        scanf("%d%d",&p,&q);

        for(int i=0;i<=1000;i++)
        {
            if(!dfs(i,p,q)) res = i;
        }

        printf("%d\n",res);
        system("pause");
        }
    return 0;
}