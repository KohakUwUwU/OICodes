//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

const int mod=100000007;
const int N=1e5+5;
struct Segment
{
	int l,r,len,val,tag;
}t[N<<2];
vector<int>G[N];
int n,m,son[N],sz[N],p[N],d[N],top[N],dfs[N],dfn[N],timer;
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].len=r-l+1;
	if(l==r)return ;
	int mid=l+r>>1;
	build(l,mid,p*2);build(mid+1,r,p*2+1);
}
inline void PushDown(int p)
{
	(t[p*2].tag+=t[p].tag)%=mod;
	(t[p*2+1].tag+=t[p].tag)%=mod;
	(t[p*2].val+=t[p].tag*t[p*2].len)%=mod;
	(t[p*2+1].val+=t[p].tag*t[p*2+1].len)%=mod;
	t[p].tag=0;
}
inline int Sum(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val%mod;
	if(x>r||y<l)return 0;
	int mid=l+r>>1;
	return (Sum(l,mid,x,y,p*2)+Sum(mid+1,r,x,y,p*2+1))%mod;
}
inline void Add(int l,int r,int x,int y,int val,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)t[p].tag=val,t[p].val+=val*t[p].len;
	if(x>r||y<l)return ;
	int mid=l+r>>1;
	Add(l,mid,x,y,val,p*2);Add(mid+1,r,x,y,val,p*2+1);
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
	if(son[fa]==u)top[u]=top[fa];
	else top[u]=u;
	if(!son[u])return ;
	dfs_top(son[u],u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==son[u]||v==fa)continue;
		dfs_top(v,u);
	}
}
inline int query(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(d[u]<d[v])swap(u,v);
		(ans+=Sum(1,n,dfn[top[u]],dfn[u],1))%=mod;
		u=p[top[u]];
	}
	return ans;
}
signed main()
{
//	freopen("company.in","r",stdin);
//	freopen("company.out","w",stdout);
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int x=read(),w=read();
		Add(1,n,dfn[x],dfn[x],w,1);
		cout<<query(1,x);
	}
	return 0;
}

