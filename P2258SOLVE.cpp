//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=25,INF=0x3f3f3f3f;
int n,m,r,c,a[N][N],ch[N],ans=INF,up[N],lft[N][N],dp[N][N];
inline int calc()
{
	memset(dp,0x3f,sizeof(dp));
	int ret=INF;
	for(int i=1;i<=m;i++)
	{
		dp[i][1]=up[i];
		for(int j=2;j<=c;j++)for(int k=1;k<i;k++)dp[i][j]=min(dp[i][j],dp[k][j-1]+up[i]+lft[k][i]);
		ret=min(ret,dp[i][c]);
	}
	return ret;
}
inline void pre()
{
	memset(up,0,sizeof(up));
	memset(lft,0,sizeof(lft));
	for(int i=1;i<r;i++)for(int j=1;j<=m;j++)up[j]+=abs(a[ch[i]][j]-a[ch[i+1]][j]);
	for(int i=1;i<=m;i++)for(int j=i+1;j<=m;j++)for(int k=1;k<=r;k++)lft[i][j]+=abs(a[ch[k]][i]-a[ch[k]][j]);
}
void dfs(int step)
{
	if(step==r+1)
	{
		pre();
		ans=min(ans,calc());
		return;
	}
	for(int i=ch[step-1]+1;i<=n;i++)
	{
		ch[step]=i;
		dfs(step+1);
		ch[step]=0;
	}
}
signed main()
{
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
