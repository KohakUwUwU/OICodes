#include<stdio.h>
int main()
{
	int dp[22]={0,1,1};
	for(int i=3;i<=20;i++)dp[i]=dp[i-1]+dp[i-2];
	for(int i=1;i<=20;i++)printf("%d\n",dp[i]);
}
