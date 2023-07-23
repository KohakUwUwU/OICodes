//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
const int INF=114514114514;
int n,m,s,f[N],vis[N];
vector<int>G[N],E[N];
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v),G[v].push_back(u);
	E[u].push_back(w),E[v].push_back(w);
}
signed main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	fill(f,f+1+n,INF);
	f[s]=0;
	for(int i=2;i<=n;i++)
	{
		int u=0;
		for(int j=1;j<=n;j++)if(f[j]<f[u]&&!vis[j])u=j;
		vis[u]=1;
		for(int j=0;j<G[u].size();j++)
		{
			int v=G[u][j];
			f[v]=min(f[v],f[u]+E[u][j]);
		}
	}
	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	return 0;
 } 
