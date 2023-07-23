//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,rt,p[N],sz[N],son[N],top[N],tI[N],tO[N],dfs[N],dfn[N],timer,d[N];
vector<int>G[N];
struct Segment
{
	int l,r,len,val,tag;
}t[N<<2];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	d[u]=d[fa]+1;
	sz[u]=1;
	son[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>=sz[son[u]])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u;
	dfn[u]=timer;
	tI[u]=timer;
	tO[u]=timer+sz[u]-1;
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
	if(l==r)
	{
		t[p]=(Segment){l,r,r-l+1,0,0};
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
}
inline void PushDown(int p)
{
	if(!t[p].tag)return ;
	t[lc].val+=t[lc].len*t[p].tag;
	t[rc].val+=t[rc].len*t[p].tag;
	t[lc].tag+=t[p].tag;
	t[rc].tag+=t[p].tag;
	t[p].tag=0;
}
inline void Add(int l,int r,int x,int y,int val,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].val+=val*t[p].len;
		t[p].tag=val;
		return ;
	}
	if(x>r||y<l)return ;
	Add(l,mid,x,y,val,lc);Add(mid+1,r,x,y,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline void add(int u,int v,int w)
{
	while(top[u]!=top[v])
	{
		if(d[top[u]]>d[top[v]])swap(u,v);
		Add(1,n,dfn[top[v]],dfn[v],w,rt);
		v=p[top[v]];
	}
	if(d[u]>d[v])swap(v,u);
	if(u==v)return ;
	Add(1,n,dfn[u]+1,dfn[v],w,rt);
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc);	
}
inline int query(int pos)
{
	return Query(1,n,tI[pos],tO[pos],rt);
}
signed main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u++,v++;
		p[v]=u;
		addEdge(u,v);
	}
	int x=n;
	while(p[x])x=p[x];
	rt=x;
	dfs_son(rt,0);
	dfs_top(rt,0);
	build(1,n,rt);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;int u,v,w;
		cin>>str;
		if(str[0]=='A')
		{
			cin>>u>>v>>w;
			u++,v++;
			add(u,v,w);
		}
		else
		{
			cin>>u;
			u++;
			cout<<query(u)<<'\n';
		}
	}
	return 0;
}

