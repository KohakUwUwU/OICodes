//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m;
int dfn[N],low[N],vis[N],timer;
int st[N],top;
int clr[N],cnt;
int du[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void tar(int u,int fa)
{
	dfn[u]=low[u]=++timer;
	st[++top]=u;
	vis[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		if(!dfn[v])tar(v,u),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++cnt;
		while(st[top]!=u)
		{
			clr[st[top]]=cnt;
			vis[st[top]]=0;
			--top;
		}
		--top;
		clr[u]=cnt;
		vis[u]=0;
	}
}
signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,addEdge(u,v);
	for(int i=1;i<=n;i++)if(!dfn[i])tar(i,0);
	for(int u=1;u<=n;u++)
	{
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(clr[u]!=clr[v])du[clr[u]]++,du[clr[v]]++;
		}
	}
	int temp=0;
	for(int i=1;i<=cnt;i++)temp+=(du[i]==2);
	cout<<(temp+1)/2;
	return 0;
}

