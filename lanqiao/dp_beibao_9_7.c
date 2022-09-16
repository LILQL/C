#include <stdio.h>
#include <stdlib.h>
#define N 1010
int n,m;
int v[N],w[N];
int f[N][N];
int max(int a,int b)
{
    return (a>b)?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i < =n i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            if(j<v[i]){
                f[i][j]=f[i-1][j];
            }
            else{
                f[i][j]=max(f[i-1][j-v[i]]+w[i],f[i-1][j]);
            }
        }
        
    }
    printf("%d",res);
    

    system("pause");
    return 0;
}