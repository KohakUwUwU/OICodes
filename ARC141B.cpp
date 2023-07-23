//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=998244353;
const int N=130;
int dp[N][N],a[N];
int n,m;
inline int Count(int m)
{
	int cnt=0;
	while(m)cnt++,m/=2;
	return cnt;
}
inline void DP(int n,int m)
{
	dp[1][0]=1;
	dp[1][1]=a[1]%MOD;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=min(i,m);j++)
		{
			(dp[i][j]=dp[i-1][j-1]*(a[i]%MOD)+dp[i-1][j])%=MOD;
		}
	}
	cout<<dp[n][m]%MOD;
}
signed main()
{
	cin>>n>>m;
	int cnt=Count(m);
//	cout<<cnt<<'\n';
	if(n>cnt)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<cnt;i++)a[i]=(1<<(i-1))%MOD;
	a[cnt]=(m-(1<<(cnt-1))+1)%MOD;
//	for(int i=1;i<=cnt;i++)cout<<a[i]<<' ';
	DP(cnt,n);
	return 0;
}

