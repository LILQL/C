#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                int d=sqrt(n-a*a-b*b-c*c);
                
                if(n==a*a+b*b+c*c+d*d)
                {
                    printf("%d %d %d %d\n",a,b,c,d);
                    system("pause");
                    return 0;
                }
            }
        }
    }
    system("pause");
    return 0;
}