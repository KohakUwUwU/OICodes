//TEmPTaTiON.
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=100000000;
int f[13][1<<12],n,m;
int g[1<<12],h[1<<12],a[13][13];
int F[13];

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)F[i]=(F[i]<<1)+a[i][j];
	for(int i=0;i<(1<<m);i++)if(!(i&(i>>1))&&!(i&(i<<1)))
	{
		g[i]=1;
		if((i&F[1])==i) f[1][i]=1;
	}
	for(int x=2;x<=n;x++)for(int j=0;j<(1<<m);j++)if(((j&F[x-1])==j)&&g[j])for(int k=0;k<(1<<m);k++)if(((k&F[x])==k)&&!(j&k)&&g[k])f[x][k]=(f[x][k]+f[x-1][j])%p;
	int ans=0;
	for(int i=0;i<(1<<m);i++)ans=(ans+f[n][i])%p;
	cout<<ans;
    return 0;
}
