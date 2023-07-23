//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,res,timer,cnter,id[N],dfn[N],tI[N],tO[N],clr[N],sz[N],son[N],cnt[N],ans[N],cntAll[N],mark[N];
vector<int>G[N],f[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
	f[u].push_back(++cnter);
	f[v].push_back(cnter);
}
inline void addNode(int u,bool ADD)
{
	int &c=clr[u];
	if(ADD)
	{
		++cnt[c];
		if(cnt[c]==1)++res;
		if(cnt[c]==cntAll[c])--res;
	}
	else --cnt[c];
}
inline void addTree(int u,int ADD)
{
	for(int i=tI[u];i<=tO[u];i++)addNode(id[i],ADD);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1;cntAll[clr[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		mark[f[u][i]]=v;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_line(int u,int fa)
{
	tI[u]=++timer;
	tO[u]=tI[u]+sz[u]-1;
	dfn[timer]=u;
	id[timer]=u;
	if(son[u])dfs_line(son[u],u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||v==son[u])continue;
		dfs_line(v,u);
	}
}
inline void dfs_work(int u,int fa,bool hvy)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==son[u]||v==fa)continue;
		dfs_work(v,u,0);
	}
	if(son[u])dfs_work(son[u],u,1);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==son[u]||v==fa)continue;
		addTree(v,1);
	}
	addNode(u,1);
	ans[u]=res;
	if(hvy)return ;
	addTree(u,0);
	res=0;
}
signed main()
{
	freopen("ctree.in","r",stdin);
	freopen("ctree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&clr[i]);
	for(int i=1,u,v;i<n;i++)scanf("%lld%lld",&u,&v),addEdge(u,v);
	dfs_son(1,0);
	dfs_line(1,0);
	dfs_work(1,0,1);
	for(int i=1;i<n;i++)printf("%lld ",ans[mark[i]]);
	return 0;
}
