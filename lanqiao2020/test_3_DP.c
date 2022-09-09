#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[5];
    int dp[5]; /*以a[i]结尾的最长子序列的长度作为状态，即为下标*/
    int res = 0;
    for (int m = 0; m < 5; m++)
    {
        scanf("%d", &a[m]);
    }
    dp[0] = 1; /*初值定义*/

    for (int i = 1; i < 5; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j < i; j++)
        {
            if (a[j] < a[i]) /*边界处理*/
            {
                dp[i] = max(dp[i], dp[j] + 1); /*状态方程*/
            }
        }
        res = max(dp[i], res); /*第i个数字经遍历后与res比较并赋值*/
    }

    printf("%d", res);
    system("pause");

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}