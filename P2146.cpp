//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,p[N],d[N],sz[N],son[N],top[N],tI[N],tO[N],dfs[N],dfn[N],timer;
vector<int>G[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
struct Segment
{
    int l,r,val,tag;
    //val维护的是线段树区间内有多少个1
    //tag维护的是线段树区间内的覆盖情况(0/1)
}t[N<<2];
inline void addEdge(int u,int v)
{
    G[u].push_back(v);
}
inline void dfs_son(int u,int fa)
{
    p[u]=fa,sz[u]=1,son[u]=0;d[u]=d[fa]+1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        dfs_son(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
    }
}
inline void dfs_top(int u,int fa)
{
	dfs[++timer]=u,dfn[u]=timer;
    tI[u]=timer;tO[u]=timer+sz[u]-1;
    if(u==son[fa])top[u]=top[fa];
    else top[u]=u;
    if(!son[u])return ;
    dfs_top(son[u],u);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==son[u])continue;
        dfs_top(v,u);
    }
}
inline void PushDown(int p)
{
    if(t[p].tag==-1)return ;
    t[lc].tag=t[rc].tag=t[p].tag;
    if(t[p].tag)
    {
        t[lc].val=t[lc].r-t[lc].l+1;
        t[rc].val=t[rc].r-t[rc].l+1;
    }
    else t[lc].val=t[rc].val=0;
    t[p].tag=-1; 
}
inline void build(int l,int r,int p)
{
    t[p]=(Segment){l,r,0,-1};
    if(l==r)return ;
    build(l,mid,lc);build(mid+1,r,rc);
}
inline int Query(int l,int r,int x,int y,int p)
{
    PushDown(p);
    if(x<=l&&r<=y)return t[p].val;
    if(x>r||y<l)return 0;
    return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc); 
}
inline void Revise(int l,int r,int x,int y,int val,int p)
{
    PushDown(p);
    if(x<=l&&r<=y)
    {
        t[p].val=(val==0?0:(t[p].r-t[p].l+1));
        t[p].tag=val;
        return ;
    }
    if(x>r||y<l)return ;
    Revise(l,mid,x,y,val,lc);
    Revise(mid+1,r,x,y,val,rc);
    t[p].val=t[lc].val+t[rc].val;
}
inline int LinkQ(int u)
{
	int ans=0;
    while(u)
    {
    	int v=top[u];
    	ans+=Query(1,n,dfn[v],dfn[u],1);
    	u=p[top[u]];
	}
	return ans;
}
inline void LinkR(int u,int x)
{
	while(u)
	{
		int v=top[u];
		Revise(1,n,dfn[v],dfn[u],x,1);
		u=p[top[u]];
	}
}
inline void install(int x)
{
	int ans=d[x]-LinkQ(x);
	LinkR(x,1);
	cout<<ans<<'\n';
}
inline void uninstall(int x)
{
	int ans=Query(1,n,tI[x],tO[x],1);
	cout<<ans<<'\n';
	Revise(1,n,tI[x],tO[x],0,1);
}
signed main()
{
    cin>>n;
    for(int i=2,u;i<=n;i++)cin>>u,addEdge(u+1,i);
    dfs_son(1,0);
	dfs_top(1,0);
    build(1,n,1);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string str;int opt;
        cin>>str>>opt;
        opt++;
        if(str=="install")install(opt);
        else uninstall(opt);
    }
    return 0;
}
