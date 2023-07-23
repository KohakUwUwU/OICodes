//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,rt,al,top,temp,adq;
int col[N],ms[N],sz[N],now[N],cbook[N],cnt[N],vis[N],Book[N],ans[N];
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
	ms[u]=max(ms[u],al-sz[u]);
	if(ms[u]<ms[rt])rt=u;
}
inline void siz(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		siz(v,u);sz[u]+=sz[v];
	}
}
inline void cunt(int u,int fa,int num,int tot)
{
	if(!now[col[u]])num++,tot+=cnt[col[u]];
	now[col[u]]++;ans[u]+=adq-tot+num*temp;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		cunt(v,u,num,tot);
	}
	now[col[u]]--;
}
inline void cld(int u,int fa)
{
	if(!now[col[u]])cnt[col[u]]-=sz[u],adq-=sz[u];
	now[col[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		cld(v,u);
	}
	now[col[u]]--;
}
inline void clr(int u,int fa)
{
	if(!now[col[u]])cnt[col[u]]+=sz[u],adq+=sz[u];
	if(!Book[col[u]])cbook[++top]=col[u],Book[col[u]]=true;
	now[col[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		clr(v,u);
	}
	now[col[u]]--;
}
inline void work(int u)
{
	siz(u,0);
	adq=0,top=0;
	clr(u,0);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(vis[v])continue;
		now[col[u]]++,cld(v,u),cnt[col[u]]-=sz[v],adq-=sz[v];
		temp=sz[u]-sz[v],cunt(v,u,0,0);
		clr(v,u),now[col[u]]--,cnt[col[u]]+=sz[v],adq+=sz[v];
	}
	ans[u]+=adq-cnt[col[u]]+sz[u];
	for(int i=1;i<=top;i++)Book[cbook[i]]=0,cnt[cbook[i]]=0;
}
inline void solve(int u)
{
	vis[u]=true;
	work(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(vis[v])continue;
		rt=0;al=sz[v];
		getrt(v,u);solve(rt);
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>col[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	ms[rt=0]=al=n;
	getrt(1,0);getrt(rt,0);solve(rt);
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
