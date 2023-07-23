#include<stdio.h>
int main()
{
	double sum=0;
	int dp[30]={0,1,1};
	for(int i=3;i<=25;i++)dp[i]=dp[i-1]+dp[i-2];
	for(int i=1;i<=20;i++)sum+=(dp[i+2]*1.0)/(dp[i+1]*1.0);
	printf("%lf",sum);
}
