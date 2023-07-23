//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,timer,a[N],v0[N],v1[N],dfs[N],dfn[N],d[N],p[N],sz[N],son[N],top[N];
string str;
vector<int>G[N];
inline int Convert(char ch)
{
	return ch=='H'?1:0;
}
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
inline void pre_val(int u,int fa)
{
	v0[u]=v0[fa];v1[u]=v1[fa];
	if(a[u])v1[u]++;
	else v0[u]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		pre_val(v,u);
	}
}
inline void dfs_son(int u,int fa)
{
	dfs[++timer]=u;dfn[u]=timer;d[u]=d[fa]+1;p[u]=fa;
	sz[u]=1;son[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	if(u==son[fa])top[u]=top[fa];
	else top[u]=u;
	if(!son[u])return ;
	dfs_top(son[u],u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||v==son[u])continue;
		dfs_top(v,u);
	}
}
inline void INIT()
{
	pre_val(1,0);
	dfs_son(1,0);
	dfs_top(1,0);
}
inline int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		u=p[top[u]];
	}
	return d[u]<d[v]?u:v;
}
inline int Ask(int u,int v,int c)
{
	int lca=LCA(u,v);
	if(c==0)
	{
		if(v0[u]+v0[v]-v0[p[lca]]-v0[lca])return 1;
		else return 0;
	}
	else
	{
		if(v1[u]+v1[v]-v1[p[lca]]-v1[lca])return 1;
		else return 0;
	}
}
signed main()
{
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++)a[i]=Convert(str[i-1]);
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	INIT();
	for(int i=1;i<=m;i++)
	{
		int u,v,c;char ch;
		cin>>u>>v>>ch;
		c=Convert(ch);
		cout<<Ask(u,v,c);
	}
	return 0;
}

