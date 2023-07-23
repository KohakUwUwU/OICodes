#include<stdio.h>
int main()
{
	int n,dp[51]={0,1,1};
	scanf("%d",&n);
	for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
	printf("%d",dp[n]);
}
