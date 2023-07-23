#include<iostream>
int dx[9]={0,1,1,2,2,-1,-1,-2,-2};
int dy[9]={0,2,-2,1,-1,2,-2,1,-1};
bool vis[35][35];
long long dp[35][35];
int n,m,x,y;
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(register int i=0;i<9;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<0||xx>n||yy<0||yy>m)continue;
		vis[xx][yy]=true;
	}
	dp[0][0]=1;
	for(register int i=0;i<=n;i++)for(register int j=0;j<=m;j++)if(!vis[i][j]){
		if(i>=1)dp[i][j]+=dp[i-1][j];
		if(j>=1)dp[i][j]+=dp[i][j-1];
	}
	printf("%lld",dp[n][m]);
}
