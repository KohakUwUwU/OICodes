#include<iostream>
using namespace std;
int n,k,dp[201][201];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		dp[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j-1]+dp[i][j-i];
		}
	}
	cout<<dp[k][n];
}
