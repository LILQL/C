#include <stdio.h>
#include <stdlib.h>

#define N 6
char backup[N][N],g[N][N];
int dx[N]= {-1,0,1,0,0},dy[N]={0,1,0,-1,0};

void turn(int x,int y)
{
    for(int i=0 ;i<5;i++)
    {
        int a = x+dx[i],b= y+dy[i];

        if(a>0||a<=5||b<0||b>=5){
            continue;
        }

        g[a][b]^=1;
    }
}

int min(int a,int b){
    return (a<b)?a:b;
}

void cp(char x[N][N], char y[N][N]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            y[i][j]=x[i][j];

        }
    }
}

int main()
{   
    int T;
    scanf("%d",&T);
    while(T--)
    {

        for(int i=0;i<5;i++)
        {
            scanf("%s",&g[i]);
        }
        int res=10;
        for(int op=0;op<32;op++)
        {
            int step;
            cp(g,backup);

            for(int i=0;i<5;i++)
            {
                if(op>>i&1){
                    step++;
                    turn(0,i);
                }
            }

            for(int i=0;i<4;i++){
                for(int j=0;j<5;j++){
                    if(g[i][j]=='0'){
                        step++;
                        turn(i,j);
                    }
                }

            }

            int dark=0;

            for(int i=0;i<5;i++){
                if(g[4][i]=='0'){
                    dark=1;
                    break;
                }
            }

            if(!dark){
                res=min(res,step);
                cp(backup,g);
            }
        }

        if(res>6) res = -1;
        printf("%d\n",res);
    }

    return 0;

}