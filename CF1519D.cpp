//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define part1 (-a[j+1]*b[i-1]-a[i-1]*b[j+1])
#define part2 (a[i-1]*b[i-1]+b[j+1]*a[j+1])
using namespace std;
//printf scanf

const int N=5e3+5;
int n,a[N],b[N],fw[N],bw[N],dp[N][N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)fw[i]=fw[i-1]+a[i]*b[i];
	for(int i=n;i>=1;i--)bw[i]=bw[i+1]+a[i]*b[i];
	for(int i=1;i<=n;i++)
	{
		dp[1][i]=bw[i+1];
		for(int j=i;j>=1;j--)
		{
			dp[1][i]+=a[j]*b[i-j+1];
		}
	}
	for(int i=2;i<=n;i++)
	{
		dp[i][n]=fw[i-1];
		for(int j=i;j<=n;j++)
		{
			dp[i][n]+=b[j]*a[n-j+i];
		}
	}
	int res=-114514;
	for(int i=2;i<=n;i++)for(int j=1;j<n;j++)dp[i][j]=dp[i-1][j+1]+part1+part2;
	for(int i=1;i<=n;i++)for(int j=n;j>=i;j--)res=max(res,dp[i][j]);
	cout<<res;
	return 0;
}

