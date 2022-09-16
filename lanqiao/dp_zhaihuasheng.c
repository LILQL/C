#include<stdio.h>
#include<stdlib.h>
#define N 1010
int T,n,m;
int f[N][N];
int w[N][N];

int max(int a,int b)
{
    return (a>b)?a:b;
}

int main(){
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&w[i][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=max(f[i-1][j]+w[i][j],f[i][j-1]+w[i][j]);
            }
        }
        printf("%d",f[i][j]);
        
    }

    system("pause");
    return 0;
}