//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e4+5;
int n,sz[N],mxz[N],mnsz=114514114514,mnid;
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		mxz[u]=max(mxz[u],sz[v]);
	}
	mxz[u]=max(mxz[u],n-sz[u]);
	if(mnsz>mxz[u])mnsz=mxz[u],mnid=u;
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	dfs(1,0);
	cout<<mnsz;
	return 0;
}

