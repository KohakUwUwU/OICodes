#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Segment
{
	int l,r,lclr,rclr,cnt,tag;
	friend bool operator == (const Segment x,const Segment y)
	{
		if(x.l!=y.l||x.r!=y.r||x.lclr!=y.lclr||x.rclr!=y.rclr||x.cnt!=y.cnt||x.tag!=y.tag)return false;
		return true;
	}
}t[N<<2];
int sz[N],son[N],p[N],d[N],top[N],timer,dfs[N],dfn[N],w[N];
Segment Null=(Segment){-1,0,0,0,0,0};
int n,m;
vector<int>G[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1;son[u]=0;p[u]=fa;d[u]=d[fa]+1;
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
	dfs[++timer]=u,dfn[u]=timer;
	if(u!=son[fa])top[u]=top[fa];
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
inline void PushUp(int p)
{
	t[p].lclr=t[lc].lclr;
	t[p].rclr=t[rc].rclr;
	t[p].cnt=t[lc].cnt+t[rc].cnt;
	if(t[lc].rclr==t[rc].lclr)t[p].cnt--;
}
inline void PushDown(int p)
{
	if(!t[p].tag)return ;
	t[lc].tag=t[rc].tag=t[lc].lclr=t[lc].rclr=t[rc].lclr=t[rc].rclr=t[p].tag;
	t[lc].cnt=t[rc].cnt=1;
	t[p].tag=0;
}
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,w[dfs[l]],w[dfs[l]],1,0};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	PushUp(p);
}
inline void Change(int l,int r,int x,int y,int val,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].lclr=t[p].rclr=t[p].tag=val;
		t[p].cnt=1;
		return ;
	}
	if(x>r||y<l)return ;
	Change(l,mid,x,y,val,lc);Change(mid+1,r,x,y,val,rc);
	PushUp(p);
}
inline Segment Merge(Segment l,Segment r)
{
	if(l==Null)return r;
	if(r==Null)return l;
	Segment ans=(Segment){l.l,r.r,l.lclr,r.rclr,l.cnt+r.cnt,0};
	if(l.rclr==r.lclr)ans.cnt--;
	return ans;
}
inline Segment Query(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p];
	if(x>r||y<l)return (Segment){-1,0,0,0,0,0};
	return Merge(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
inline void DYE(int u,int v,int clr)
{
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		Change(1,n,dfn[top[u]],dfn[u],clr,1);
		u=p[top[u]];
	}
	if(d[u]>d[v])swap(u,v);
	Change(1,n,dfn[u],dfn[v],clr,1);
}
inline Segment Reverse(Segment x)
{
	return (Segment){x.l,x.r,x.rclr,x.lclr,x.cnt,0};
}
inline Segment QUERY(int u,int v)
{
	Segment uSide=Null,vSide=Null;
	while(top[u]!=top[v])
	{
		if(d[top[u]]>d[top[v]])
		{
			uSide=Merge(uSide,Query(1,n,dfn[top[u]],dfn[u],1));
			u=p[top[u]];
		}
		else
		{
			vSide=Merge(Query(1,n,dfn[top[v]],dfn[v],1),vSide);
			v=p[top[v]];
		}
	}
	if(d[u]<d[v])return Merge(Reverse(Merge(Query(1,n,dfn[v],dfn[u],1),uSide)),vSide);
	else return Merge(Reverse(Merge(Query(1,n,dfn[u],dfn[v],1),vSide)),uSide);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char op,a,b,c;
		cin>>op>>a>>b;
		if(op=='C')cin>>c,DYE(a,b,c);
		else cout<<QUERY(a,b).cnt;
	}
	return 0;
}
