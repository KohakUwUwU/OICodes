#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Segment
{
	int l,r,val;
}t[N<<2];
int n,a[N],d[N],sz[N],top[N],son[N],dfs[N],dfn[N],timer;
int idtou[N];
vector<int>G[N];
vector<pair<int,int> >E[N];
inline void addEdge(int u,int v,int w,int id)
{
	G[u].push_back(v),G[v].push_back(u);
	E[u].push_back(make_pair(w,id)),E[v].push_back(make_pair(w,id));
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1;son[u]=0;d[u]=d[fa]+1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		a[v]=E[u][i].first;
		idtou[E[u][i].second]=v;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u;
	dfn[u]=timer;
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
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,a[dfs[l]]};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val=max(t[lc].val,t[rc].val);
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
    return max(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
inline int QUERY(int x,int y)
{
	//double light link
	//at last u=v=lca(u,v)
	//so no extra operation
	//one light one heavy
	//at last {u,v}={lca(u,v),?}
	//so update dfn[lca]+1~dfn[?]
	int ans=0;
	while(top[x]!=top[y])
	{
		if(d[top[x]]>d[top[y]])swap(x,y);
		ans=max(ans,Query(1,n,dfn[top[y]],dfn[y],1));
		y=top[y];
	}
	if(d[x]>d[y])swap(x,y);
	if(x!=y)ans=max(ans,Query(1,n,dfn[x]+1,dfn[y],1));
	return ans;
}
inline void Change(int l,int r,int x,int val,int p)
{
	if(l==r)
	{
		t[p].val=val;
		return ;
	}
	if(x<=mid)Change(l,mid,x,val,lc);
	else Change(mid+1,r,x,val,rc);
	t[p].val=max(t[lc].val,t[rc].val);
}
inline void CHANGE(int x,int val)
{
    Change(1,n,dfn[x],val,1);
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w,i);
	}
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	while(1)
	{
		string opt;
		cin>>opt;
		if(opt=="DONE")break;
		if(opt=="QUERY")
		{
			int x,y;
			cout<<QUERY(x,y)<<'\n';
		}
		else 
		{
			int id,val;
			cin>>id>>val;
			int u=idtou[id];
			CHANGE(u,val);
		}
	}
	return 0;
}
