#include <stdio.h>
#include <stdlib.h>
#define N 20
int n=9;
int target;
int cnt=0;
int st[N];
int used[N];//判重

int num(int start, int end)
{
    int res=0;
    for(int i=start;i<=end;i++){
        res=res*10+st[i];//很好的数组转数字方法
    }
    return res;
}

//全排列+结果分组处理+与目标对比
int dfs(int u)
{
    if(u>n)
    {
        //三段两刀
        for (int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                int a= num(1,i);
                int b= num(i+1,j);
                int c= num(j+1,9);
                //移项处理减小误差
                if(a*c+b==c*target){
                    cnt++;
                    printf("100=%d+%d/%d\n",a,b,c);
                }
            }
        }
        return;
    }

    

    for (int i=1;i<=9;i++)
    {
        if(!used[i])
        {
            st[u]=i;
            used[i]=1;
            dfs(u+1);
            st[u]=0;
            used[i]=0;
        }
    }
}


int main()
{
    scanf("%d",&target);
    dfs(1);
    printf("%d",cnt);
    system("pause");
    return 0;
}