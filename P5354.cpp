#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

const int N=1e5+7,INF=(int)0-(int)1;
int n,m,k,tiemr,d[N],p[N],sz[N],son[N],top[N],tI[N],tO[N],dfn[N];
struct Node
{
	int opt,x;
}node[N];
struct Segment
{
	int l,r,len,l0,r0,l1,r1;
}t[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	d[u]=d[fa]+1,p[u]=fa,sz[u]=1,son[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_top(int u)
{
	dfn[++tiemr]=u,tI[u]=timer,tO[u]=timer+sz[u]-1;
	if(u==son[p[u]])top[u]=top[p[u]];
	else top[u]=u;
	if(!son[u])return ;
	dfs_top(son[u]);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==p[u]||v==son[u])continue;
		dfs_top(v);
	}
}
inline int pass(int id,int num)
{
	if(node[id].opt==1)return num&node[id].x;
	if(node[id].opt==2)return num|node[id].x;
	if(node[id].opt==3)return num^node[id].x;
}
inline Segment calc(Segment l,Segment r,int left,int right)
{
	Segment res;
	res.l=left,res.r=right,res.len=r-l+1;
	res.l0=((l.l0&&r.l1)||((~l.l0)&&r.l0));
	res.r0=((r.r0&&l.r1)||((~r.r0)&&l.r0));
	res.l1=((l.l1&&r.l1)||((~l.l1)&&r.l0));
	res.r1=((r.r1&&l.r1)||((~r.r1)&&l.l0));
	return res;
}
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].len=r-l+1;
	if(l==r)
	{
		t[p].l0=t[p].r0=pass(l,(int)0);
		t[p].l1=t[p].r1=pass(l,INF);
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,p*2),build(mid+1,r,p*2+1);
	t[p]=calc(t[p*2],t[p*2+1],t[p].l,t[p].r);
}
inline int query()
{
	
}
inline int poppin(int x,int y,int z)
{
	stack<pair<int,int> >ds;
	Segment ans0,ans1;
	int u=x,v=y;
	while(top[u]!=top[v])
	{
		if(d[u]>d[v])//u «r to l
		{
			ans0=calc(0,0,ans0,)
		}
		else
		{
			
		} 
	}
}
inline void party(int x,int y,int z)
{
	
}
inline void work(int q,int x,int y,int z)
{
	if(q==1)cout<<poppin(x,y,z);//—ØŒ  
	else party(x,y,z);//–ﬁ∏ƒ 
}
signed main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)node[i].opt=read(),node[i].x=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0),dfs_top(1),build(1,n,1);
	for(int i=1,q,x,y,z;i<=m;i++)q=read(),x=read(),y=read(),z=read(),work(q,x,y,z);
	return 0;
}

