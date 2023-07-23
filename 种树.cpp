//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,w[N],sz[N],f[N],d[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs1(int u,int fa)
{
	sz[u]=w[u];d[u]=d[fa]+1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
inline void dfs2(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		f[v]=f[u]+sz[1]-2*sz[v];
		dfs2(v,u);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	d[0]=-1;
	dfs1(1,0);//求子树和
	for(int i=1;i<=n;i++)f[1]+=w[i]*d[i];
	dfs2(1,0);//动态规划 
	int ans=114514114514;
	for(int i=1;i<=n;i++)ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}

