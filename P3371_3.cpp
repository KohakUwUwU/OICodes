//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int INF=114514114514;
int n,m,s,f[N],vis[N];
vector<int>G[N],E[N];
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v);E[u].push_back(w);
}
signed main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(u==v)continue;
		addEdge(u,v,w);
	}
	fill(f,f+1+n,INF);f[s]=0;
	for(int t=2;t<=n;t++)
	{
		int u=0;
		for(int i=1;i<=n;i++)if(f[u]>f[i]&&!vis[i])u=i;
		if(u==0)continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			f[v]=min(f[v],f[u]+E[u][i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==INF)cout<<(1ll<<31)-1<<' ';
		else cout<<f[i]<<' ';
	}
	return 0;
}
