//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=105;
const int INF=114514114514;
int n,m,s,t,f[N][N];
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
	}
	for(int u=1;u<=n;u++)f[u][u]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int ans=(s-t)*(s-t);
	ans=min(ans,f[s][t]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		ans=min(ans,f[s][i]+(i-j)*(i-j)+f[j][t]);
	}
	cout<<ans;
	return 0;
}

