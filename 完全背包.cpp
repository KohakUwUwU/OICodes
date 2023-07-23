#include<iostream>
using namespace std;
int main()
{
	int m,n,dp[101][101];
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int w,c;
		cin>>w>>c;
		for(int j=1;j<w;j++)dp[i][j]=dp[i-1][j];
		for(int j=w;j<=m;j++)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+c);
	}
	cout<<dp[n][m];
}
