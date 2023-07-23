#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std;
int n,m,k,maper,timer,bl,tI[N],tO[N],dfn[N],clr[N],sz[N],son[N],cnt[N],ans[N];
map<int,int>ys;
vector<int>G[N];
struct query
{
	int l,r,id,pos;
}q[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void pre(int u,int fa)
{
	dfn[++timer]=u,tI[u]=timer;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		pre(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
	tO[u]=timer;
}
inline bool cmp(query x,query y)
{
	return x.pos!=y.pos?x.pos<y.pos:(x.l/bl&1?x.r<y.r:x.r>y.r);
}
inline void work()
{
	int l=1,r=0,cur=0;
	for(int i=1;i<=m;i++)
	{
		while(q[i].l<l)
		{
			if(cnt[clr[dfn[--l]]]==k)cur--;
			if(++cnt[clr[dfn[l]]]==k)cur++;
		}
//		cout<<cur<<' ';
		while(q[i].r>r)
		{
			if(cnt[clr[dfn[++r]]]==k)cur--;
			if(++cnt[clr[dfn[r]]]==k)cur++;
		}
//		cout<<cur<<' ';
		while(q[i].l>l)
		{
			if(cnt[clr[dfn[l]]]==k)cur--;
			if(--cnt[clr[dfn[l++]]]==k)cur++;
		}
//		cout<<cur<<' ';
		while(q[i].r<r)
		{
			if(cnt[clr[dfn[r]]]==k)cur--;
			if(--cnt[clr[dfn[r--]]]==k)cur++;
		}
//		cout<<cur<<' ';
		ans[q[i].id]=cur;
//		cout<<'\n'<<l<<' '<<r<<' ';
//		for(int i=1;i<=3;i++)cout<<cnt[i]<<' ';
//		cout<<'\n'; 
	}
}
/*
3 1
3 3 2
2 1
3 2
3
2 1 1
*/
//2 1 1
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u;
		cin>>u;
		if(!ys[u])ys[u]=++maper;
		clr[i]=ys[u];
	}
//	for(int i=1;i<=n;i++)cout<<clr[i]<<' ';
//	cout<<'\n';
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	pre(1,0);
	bl=sqrt(n);
	cin>>m;
	for(int i=1,u;i<=m;i++)cin>>u,q[i]=(query){tI[u],tO[u],i,tI[u]/bl+1};
	sort(q+1,q+1+m,cmp);
	work();
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
