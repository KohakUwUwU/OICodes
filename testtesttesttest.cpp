//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,col[N],rt,sum,top,Y,ms[N],sz[N],now[N],cbook[N],cnt[N],vis[N],Book[N],Sum,ans[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void getrt(int u,int fa)
{
	sz[u]=1,ms[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		getrt(v,u);sz[u]+=sz[v];
		ms[u]=max(ms[u],sz[v]);
	}
	ms[u]=max(ms[u],sum-sz[u]);
	if(ms[u]<ms[rt])rt=u;
}
inline void getsz(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		getsz(v,u);sz[u]+=sz[v];
	}
}
inline void getcol(int u,int fa)
{
	if(!now[col[u]])cnt[col[u]]+=sz[u],Sum+=sz[u];
	if(!Book[col[u]])cbook[++top]=col[u],Book[col[u]]=true;
	now[col[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		getcol(v,u);
	}
	now[col[u]]--;
}
inline void delcol(int u,int fa)
{
	if(!now[col[u]])cnt[col[u]]-=sz[u],Sum-=sz[u];
	now[col[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		delcol(v,u);
	}
	now[col[u]]--;
}
inline void Count(int u,int fa,int num,int tot)
{
	if(!now[col[u]])num++,tot+=cnt[col[u]];
	now[col[u]]++;ans[u]+=Sum-tot+num*Y;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		Count(v,u,num,tot);
	}
	now[col[u]]--;
}
inline void work(int u)
{
	getsz(u,0);
	Sum=0,top=0;
	getcol(u,0);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(vis[v])continue;
		now[col[u]]++,delcol(v,u),cnt[col[u]]-=sz[v],Sum-=sz[v];
		Y=sz[u]-sz[v],Count(v,u,0,0);
		getcol(v,u),now[col[u]]--,cnt[col[u]]+=sz[v],Sum+=sz[v];
	}
	ans[u]+=Sum-cnt[col[u]]+sz[u];
	for(int i=1;i<=top;i++)Book[cbook[i]]=false,cnt[cbook[i]]=0;
}
inline void solve(int u)
{
	vis[u]=true;
	work(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(vis[v])continue;
		rt=0;sum=sz[v];
		getrt(v,u);solve(rt);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>col[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	ms[rt=0]=sum=n;
	getrt(1,0);getrt(rt,0);solve(rt);
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
