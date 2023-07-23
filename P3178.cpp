//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Segment
{
	int l,r,len,val,tag;
}t[N<<2];
int n,m,a[N],sz[N],son[N],top[N],timer,tI[N],tO[N],p[N],dfn[N],dfs[N],d[N];
vector<int>G[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0,p[u]=fa,d[u]=d[fa]+1;
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
	dfs[++timer]=u,dfn[u]=timer;
	tI[u]=timer,tO[u]=timer+sz[u]-1;
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
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,r-l+1,a[dfs[l]],0};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline void PushDown(int p)
{
	t[lc].tag+=t[p].tag;
	t[rc].tag+=t[p].tag;
	t[lc].val+=t[p].tag*t[lc].len;
	t[rc].val+=t[p].tag*t[rc].len;
	t[p].tag=0;
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc);
}
inline void Add(int l,int r,int x,int y,int val,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].tag=val;
		t[p].val+=t[p].len*val;
		return ;
	}
	if(x>r||y<l)return ;
	Add(l,mid,x,y,val,lc);Add(mid+1,r,x,y,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline int Jump(int x)
{
	int ans=0;
	while(x)
	{
		ans+=Query(1,n,dfn[top[x]],dfn[x],1);
		x=p[top[x]];
	}
	return ans;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int opt,x,a;
		cin>>opt;
		switch(opt)
		{
		case 1:
			cin>>x>>a;
			Add(1,n,dfn[x],dfn[x],a,1);
			break;
		case 2:
			cin>>x>>a;
			Add(1,n,tI[x],tO[x],a,1);
			break;
		case 3:
			cin>>x;
			cout<<Jump(x)<<'\n';
			break;
		}
	}
	return 0;
}

