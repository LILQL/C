#include <stdlib.h>
#include <stdio.h>

int n,q;
int s[100010];

int main()
{
    scanf("%d%d",&n,&q);
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }

    for(int i=0;i<q;i++)
    {
        int x;
        int l=0;
        int r=n-1;
        scanf("%d",&x);
        while(l<r)
        {
            int mid=(l+r)/2;
            if(s[mid]>=x){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(s[r]==x){
            printf("%d\t",r);
            l=0;
            r=n-1;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(s[mid]<=x){
                    l=mid;
                }else{
                    r=mid-1;
                }
            }
            printf("%d\n",l);
        }else{
            printf("-1\t-1");
        }
    }
    system("pause");
    return 0;
}