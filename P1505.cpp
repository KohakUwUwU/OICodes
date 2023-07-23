#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct Segment
{
	int l,r,sum,max,min;
	bool rev;
}t[N<<2];
int n,m;
int val[N],id[N],sz[N],son[N],top[N],p[N],d[N],dfs[N],dfn[N],timer;
vector<int>G[N];
vector<pair<int,int> >E[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void addEdge(int u,int v,int w,int i)
{
	G[u].push_back(v),G[v].push_back(u);
	E[u].push_back(make_pair(w,i));
	E[v].push_back(make_pair(w,i));
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1;son[u]=0;d[u]=d[fa]+1;p[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		val[v]=E[u][i].first;
		id[v]=E[u][i].second;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u,dfn[u]=timer;
	if(u==son[fa])top[u]=top[fa];
	else top[u]=u;
	if(son[u])return ;
	dfs_top(son[u],u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||v==son[u])continue;
		dfs_top(v,u);
	}
}
inline void PushDown(int p)
{
	if(!t[p].rev)return ;
	t[lc].rev=!t[lc].rev;
	t[rc].rev=!t[rc].rev;
	t[lc].sum=-t[lc].sum;
	t[rc].sum=-t[rc].sum;
	t[lc].max=-t[lc].max;
	t[rc].max=-t[rc].max;
	t[lc].min=-t[lc].min;
	t[rc].min=-t[rc].min;
	swap(t[lc].min,t[lc].max);
	swap(t[rc].min,t[rc].max);
	t[p].rev=false;
}
inline void PushUp(int p)
{
	t[p].max=max(t[lc].max,t[rc].max);
	t[p].min=min(t[lc].min,t[rc].min);
	t[p].sum=t[lc].sum+t[rc].sum;
}
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,val[dfs[l]],val[dfs[l]],val[dfs[l]],0};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	PushUp(p);
}
inline void Change(int l,int r,int pos,int val,int p)
{
	if(l!=r)PushDown(p);
	if(l==r)
	{
		t[p].sum=t[p].min=t[p].max=val;
		return ;
	}
	if(pos<=mid)Change(l,mid,pos,val,lc);
	else Change(mid+1,r,pos,val,rc);
	PushUp(p);
}
inline void Reverse(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].sum=-t[p].sum;
		t[p].min=-t[p].min;
		t[p].max=-t[p].max;
		swap(t[p].min,t[p].max);
	}
	if(x>r||y<l)return ;
	Reverse(l,mid,x,y,lc);
	Reverse(mid+1,r,x,y,rc);
	PushUp(p);
}
inline int Sum(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].sum;
	if(x>r||y<l)return 0;
	return Sum(l,mid,x,y,lc)+Sum(mid+1,r,x,y,rc);
}
inline int Min(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].min;
	if(x>r||y<l)return 114514114514;
	return min(Min(l,mid,x,y,lc),Min(mid+1,r,x,y,rc));
}
inline int Max(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].max;
	if(x>r||y<l)return -114514114514;
	return max(Max(l,mid,x,y,lc),Max(mid+1,r,x,y,rc));
}
inline void REVISE(int k,int val)
{
	int u=id[k];
	Change(1,n,k,val,1);
}
inline void REVERSE(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		Reverse(1,n,dfn[top[u]],dfn[u],1);
		u=p[top[u]];
	}
	if(u==v)return ;
	if(d[u]>d[v])swap(u,v);
	Reverse(1,n,dfn[son[u]],dfn[v],1);
}
inline int SUM(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		ans+=Sum(1,n,dfn[top[u]],dfn[u],1);
		u=p[top[u]];
	}
	if(u==v)return ans;
	if(d[u]>d[v])swap(u,v);
	ans+=Sum(1,n,dfn[son[u]],dfn[v],1);
	return ans;
}
inline int MIN(int u,int v)
{
	int ans=114514114514;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		ans=min(ans,Min(1,n,dfn[top[u]],dfn[u],1));
		u=p[top[u]];
	}
	if(u==v)return ans;
	if(d[u]>d[v])swap(u,v);
	ans=min(ans,Min(1,n,dfn[son[u]],dfn[v],1));
	return ans;
}
inline int MAX(int u,int v)
{
	int ans=-114514114514;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])swap(u,v);
		ans=max(ans,Max(1,n,dfn[top[u]],dfn[u],1));
		u=p[top[u]];
	}
	if(u==v)return ans;
	if(d[u]>d[v])swap(u,v);
	ans=max(ans,Max(1,n,dfn[son[u]],dfn[v],1));
	return ans;
}
inline void print()
{
	cout<<"LizPlum"<<'\n';
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u++;v++;
		addEdge(u,v,w,i-1);
	}
	dfs_son(1,0);
	dfs_top(1,0);
	build(1,n,1);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		int x,y;
		cin>>str>>x>>y;
		if(str=="C")REVISE(x,y);
		else if(str=="M")REVERSE(x+1,y+1);
		else if(str=="SUM")cout<<SUM(x+1,y+1)<<'\n';
		else if(str=="MAX")cout<<MAX(x+1,y+1)<<'\n';
		else cout<<MIN(x+1,y+1)<<'\n';
	}
	return 0;
}
