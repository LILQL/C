#include<stdio.h>
#include<stdlib.h>
int m=0;
int main()
{
    char a,b,c;
    int n;
    scanf("%d",&n);
    a="A",b="B",c="C";
    void move(int n,char a,char c)
    {
        printf("转移次数:%d,从%c到%c",++m,a,c);
    }
    void hanoi(int n,char a,char b,char c)
    {
        if(n==1){
            move(1,a,c);
        }else{
            hanoi(n-1,a,c,b);
            move(a,n,c);
            hanoi(n-1,b,a,c);
        }
    }
    system("pause");
    return 0;
}