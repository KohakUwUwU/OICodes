#include<iostream>
using namespace std; 
long long m,n,dp[101][101];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[m][n];
}
