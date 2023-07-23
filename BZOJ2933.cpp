//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e3+5;
int n,m,a[N],dp[N][20],w[N][N],sum[N];
#define mid (i+j>>1)
#define pre sum[j]-sum[mid]
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=a[mid]*(mid-i)-(sum[mid-1]-sum[i-1])-a[mid]*(j-mid)+pre;
	for(int i=1;i<=n;i++)for(int j=0;j<20;j++)dp[i][j]=114514114514;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<i;k++)dp[i][j]=min(dp[i][j],dp[k][j-1]+w[k+1][i]);
	cout<<dp[n][m];
	return 0;
} 
