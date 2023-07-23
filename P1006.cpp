#include<iostream>
using namespace std;
short i,j,k,l,m,n,ma[101][101],dp[101][101][101][101];
int main()
{
	scanf("%hd%hd",&m,&n);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)scanf("%hd",&ma[i][j]);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)for(int l=1;l<=n;l++)
	{
		dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])))+ma[i][j]+ma[k][l];
		if(i==k&&j==l)dp[i][j][k][l]-=ma[i][j];
	}
	cout<<dp[m][n][m][n];
}
