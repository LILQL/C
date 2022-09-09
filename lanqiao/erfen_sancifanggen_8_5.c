#include <stdio.h>
#include <stdlib.h>
double n,l,r,mid;
int main(){
    scanf("%lf",&n);
    l=-10000,r=10000;
    while((r-l)>=1e-8){
        mid=(l+r)/2;
        if(mid*mid*mid>=n) r=mid;
        else l=mid;
    }
    printf("%.6lf",l);
    system("pause");
    return 0;
}