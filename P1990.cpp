#include<stdio.h>
int dp[1000009]={0,1,2,5},n;
int main()
{
	scanf("%d",&n);
	for(int i=4;i<=n;i++)dp[i]=(dp[i-1]*2+dp[i-3])%10000;
	printf("%d",dp[n]);
}
