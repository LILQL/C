#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mod = 1e4;
typedef long long LL;
LL dp[20190325];
int main()
{
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i < 20190325; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }
    printf("%lld", dp[20190324]);
    system("pause");
    return 0;
}