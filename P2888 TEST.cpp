//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=305;
const int INF=114514114514;
int n,m,t,f[N][N];
inline void addEdge(int u,int v,int w)
{
	f[u][v]=w;
}
inline void Floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			}
		}
	}
}
signed main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	Floyd();
	for(int i=1;i<=t;i++)
	{
		int u,v;
		cin>>u>>v;
		if(f[u][v]==INF)cout<<"-1\n";
		else cout<<f[u][v]<<'\n';
	}
	return 0;
}

