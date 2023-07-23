//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,r,mod,a[N],sz[N],son[N],top[N],tI[N],tO[N],dfs[N],dfn[N],p[N],d[N],timer;
vector<int>G[N];
struct Segment
{
	int l,r,len,val,tag;
}t[N<<2];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0;p[u]=fa;d[u]=d[fa]+1;
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
	t[p]=(Segment){l,r,r-l+1,0,0};
	if(l==r)
	{
		(t[p].val=a[dfs[l]])%=mod;
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	(t[p].val=t[lc].val+t[rc].val)%=mod;
}
inline void PushDown(int p)
{ 
	if(!t[p].tag)return ;
	(t[lc].tag+=t[p].tag)%=mod;
	(t[rc].tag+=t[p].tag)%=mod;
	(t[lc].val+=t[p].tag*t[lc].len)%=mod;
	(t[rc].val+=t[p].tag*t[rc].len)%=mod;
	t[p].tag=0;
}
inline int Query(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	return (Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc))%mod;
}
inline void Revise(int l,int r,int x,int y,int val,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)
	{
		(t[p].val+=val*t[p].len)%=mod;
		(t[p].tag=val)%=mod;
		return ;
	}
	if(x>r||y<l)return ;
	Revise(l,mid,x,y,val,lc);Revise(mid+1,r,x,y,val,rc);
	(t[p].val=t[lc].val+t[rc].val)%=mod;
}
inline void LinkR(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		Revise(1,n,dfn[top[x]],dfn[x],z,1);
		x=p[top[x]];
	}
	if(d[x]>d[y])swap(x,y);
	Revise(1,n,dfn[x],dfn[y],z,1);
}
inline int LinkQ(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		(ans+=Query(1,n,dfn[top[x]],dfn[x],1))%=mod;
		x=p[top[x]];
	}
	if(d[x]>d[y])swap(x,y);
	(ans+=Query(1,n,dfn[x],dfn[y],1))%=mod;
	return ans;
}
inline void SbtR(int x,int z)
{
	Revise(1,n,tI[x],tO[x],z,1);
}
inline int SbtQ(int x)
{
	return Query(1,n,tI[x],tO[x],1)%mod;
}
signed main()
{
	cin>>n>>m>>r>>mod;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]%=mod;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	dfs_son(r,0);
	dfs_top(r,0);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		cin>>op;
		switch(op)
		{
		case 1:
			cin>>x>>y>>z;
			z%=mod;
			LinkR(x,y,z);
			break;
		case 2:
			cin>>x>>y;
			cout<<LinkQ(x,y)<<'\n';
			break;
		case 3:
			cin>>x>>z;
			z%=mod;
			SbtR(x,z);
			break;
		case 4:
			cin>>x;
			cout<<SbtQ(x)<<'\n';
			break;
		}
	}
	return 0;
}
