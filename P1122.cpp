//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=16005;
int f[N],n,p[N],a[N],sz[N],ans; 
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=a[u];p[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
	}
}
inline void dfs_f(int u,int fa)
{
	f[u]=a[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_f(v,u);
		if(f[v]>0)f[u]+=f[v];
	}
	ans=max(ans,f[u]);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	dfs_son(1,0);
	dfs_f(1,0);
	cout<<ans;
	return 0;
}

