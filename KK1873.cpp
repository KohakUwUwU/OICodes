//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,res,timer,path[N],cnt[N],sz[N],top[N],son[N],tI[N],tO[N],id[N],ans[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void useNode(int v,int lca)
{
	res+=cnt[path[v]^lca];
}
inline void useTree(int v,int lca)
{
	for(int i=tI[v];i<=tO[v];i++)useNode(id[i],lca);
}
inline void addNode(int u,bool ADD)
{
	if(ADD)++cnt[path[u]];
	else --cnt[path[u]];
}
inline void addTree(int u,bool ADD)
{
	for(int i=tI[u];i<=tO[u];i++)addNode(id[i],ADD);
}
inline void dfs_son(int u,int fa)
{
	path[u]=path[fa]^u;
	tI[u]=++timer;
	id[timer]=u;
	sz[u]=1,son[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
	tO[u]=timer;
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
	res=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==son[u]||v==fa)continue;
		useTree(v,u),addTree(v,1);
	}
	useNode(u,u),addNode(u,1);
	ans[u]=res;
	if(hvy)return ;
	addTree(u,0);
}
signed main()
{
	freopen("xor3.in","r",stdin);
	freopen("xor3.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;i++)scanf("%lld%lld",&u,&v),addEdge(u,v);
	dfs_son(1,0);
	dfs_work(1,0,1);
	int re=0;
	for(int i=1;i<=n;i++)re+=ans[i];
	printf("%lld",re); 
	return 0;
}
