//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e4+5;
int n,m,val[N],sz[N],son[N],top[N],p[N],dfn[N],dfs[N],d[N],timer;
vector<int>G[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
struct Segment
{
	int l,r,sum,max;
}t[N<<2];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
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
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u,dfn[u]=timer;
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
	t[p]=(Segment){l,r,0,0};
	if(l==r)
	{
		t[p].sum=t[p].max=val[dfs[l]];
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].sum=t[lc].sum+t[rc].sum;
	t[p].max=max(t[lc].max,t[rc].max);
}
inline void Revise(int l,int r,int pos,int val,int p)
{
	if(l==r)
	{
		t[p].sum=t[p].max=val;
		return ;
	}
	if(pos<=mid)Revise(l,mid,pos,val,lc);
	else Revise(mid+1,r,pos,val,rc);
	t[p].max=max(t[lc].max,t[rc].max);
	t[p].sum=t[lc].sum+t[rc].sum;
}
inline int Sum(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].sum;
	if(x>r||y<l)return 0;
	return Sum(l,mid,x,y,lc)+Sum(mid+1,r,x,y,rc);
}
inline int Max(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].max;
	if(x>r||y<l)return -114514114514;
	return max(Max(l,mid,x,y,lc),Max(mid+1,r,x,y,rc));
}
inline int Qmax(int u,int v)
{
	int mx=-114514114514;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		mx=max(mx,Max(1,n,dfn[top[u]],dfn[u],1));
		u=p[top[u]];
	}
	if(d[u]<d[v])swap(u,v);
	mx=max(mx,Max(1,n,dfn[v],dfn[u],1));
	return mx;
}
inline int Qsum(int u,int v)
{
	int sum=0;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		sum+=Sum(1,n,dfn[top[u]],dfn[u],1);
		u=p[top[u]];
	}
	if(d[u]<d[v])swap(u,v);
	sum+=Sum(1,n,dfn[v],dfn[u],1);
	return sum;
}
signed main()
{
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	for(int i=1;i<=n;i++)cin>>val[i];
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		int a,b;
		cin>>str>>a>>b;
		if(str=="QMAX")cout<<Qmax(a,b)<<'\n';
		else if(str=="QSUM")cout<<Qsum(a,b)<<'\n';
		else Revise(1,n,a,b,1);
	}
	return 0;
}

