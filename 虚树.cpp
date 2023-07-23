//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,k,group[N],p[N],d[N],dfs[N],dfn[N],tI[N],tO[N],son[N],top[N],sz[N],rt[N],timer;
vector<int>q[N];
vector<int>G[N],F[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void virLink(int u,int v)
{
	F[u].push_back(v),F[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	p[u]=fa;d[u]=d[fa]+1;
	son[u]=0;
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u;
	dfn[u]=timer;
	tI[u]=timer;
	q[group[u]].push_back(u);
	if(u==son[fa])top[u]=top[fa];
	else top[u]=u;
	if(!son[u])return ;
	dfs_top(son[u],u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||v==son[u])continue;
		dfs(v,u);
	}
	tO[u]=timer;
}
inline int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(d[top[u]]>d[top[v]])swap(u,v);
		v=p[top[v]];
	}
	if(d[u]>d[v])return v;
	else return u;
}
inline bool cmp(int u,int v)
{
	return dfn[u]<dfn[v];
}
stack<int>st;
inline void Link(int k)
{
	st.clear();
	st.push(q[k][0]);
	rt[k]=q[k][0];
	for(int i=1;i<q[k].size();i++)
	{
		int u=q[k][i];
		int top=st.top();
		while(!(tI[top]<=dfn[u]&&dfn[u]<=tO[top]))st.pop(),top=st.top();
		virLink(top,u);
	}
}
inline void DP(int k)
{
	
}
signed main()
{
	cin>>n>>k;
	for(int u=1;u<=n;u++)
	{
		int v;
		cin>>group[u]>>v;
		if(v)addEdge(u,v);
	}
	dfs_son(1,0);
	dfs_top(1,0);
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<q[i].size()-1;j++)
		{
			int u=q[i][j],v=q[i][j+1];
			int lca=LCA(u,v);
			if(lca!=u&&lca!=v)q[i].push_back(lca);
		}
		sort(q[i].begin(),q[i].end(),cmp);
		Link(i);
		DP(i);
	}
	return 0;
}

