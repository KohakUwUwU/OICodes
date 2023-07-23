//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
int n,c,pos[N],power[N],fr[N];
int dp[N][N][2],INF;
signed main()
{
	cin>>n>>c;
	for (int i=1;i<=n;i++)cin>>pos[i]>>power[i],fr[i]=fr[i-1]+power[i];
	memset(dp,42,sizeof(dp));
	INF=dp[c][c][0];
	dp[c][c][0]=dp[c][c][1]=0;
	for (int i=c;i<=n;i++)
		for (int j=i-1;j>=1;j--)
		{
			int sum=fr[j-1]+fr[n]-fr[i];
			dp[j][i][0]=min(dp[j][i][0],dp[j+1][i][0]+(sum+power[j])*(pos[j+1]-pos[j]));
			dp[j][i][0]=min(dp[j][i][0],dp[j+1][i][1]+(sum+power[j])*(pos[i]-pos[j]));
			dp[j][i][1]=min(dp[j][i][1],dp[j][i-1][1]+(sum+power[i])*(pos[i]-pos[i-1]));
			dp[j][i][1]=min(dp[j][i][1],dp[j][i-1][0]+(sum+power[i])*(pos[i]-pos[j]));
		}
	cout<<min(dp[1][n][0],dp[1][n][1]);
	return 0;
}
