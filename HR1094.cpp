#include<stdio.h>
int dp[101][101],n;
int main()
{
	dp[1][1]=1;
	scanf("%d",&n);
	puts("1");
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
}
