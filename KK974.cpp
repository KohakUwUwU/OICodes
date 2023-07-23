#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

const int N=1e5+7;
struct segment
{
	int l,r,val,add;
}t[N*4];
int n,m,timer,d[N],p[N],sz[N],son[N],top[N],tI[N],tO[N],dfn[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].val=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline void spread(int p)
{
	if(t[p].add!=2)
	{
		t[p*2].val=t[p].add*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].val=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
		t[p*2].add=t[p].add;t[p*2+1].add=t[p].add;
		t[p].add=2;
	}
}
inline void change(int p,int x,int y,int k)
{
	if(x<=t[p].l&&t[p].r<=y)
	{
		t[p].add=k;
		t[p].val=k*(t[p].r-t[p].l+1);
		return ;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(x<=mid)change(p*2,x,y,k);
	if(y>mid)change(p*2+1,x,y,k);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline int ask(int p,int x,int y)
{
	if(x<=t[p].l&&t[p].r<=y)return t[p].val;
	spread(p);
	int ans=0,mid=(t[p].l+t[p].r)>>1;
	if(x<=mid)ans+=ask(p*2,x,y);
	if(y>mid)ans+=ask(p*2+1,x,y);
	return ans;
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0,p[u]=fa,d[u]=d[fa]+1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_top(int u)
{
	dfn[++timer]=u,tI[u]=timer,tO[u]=timer+sz[u]-1;
	if(u==son[p[u]])top[u]=top[p[u]];
	else top[u]=u;
	if(!son[u])return ;
	dfs_top(son[u]);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==son[u])continue;
		dfs_top(v);
	}
}
inline void holiday(int x)
{
	int ans=0;
	while(x)
	{
		ans+=ask(1,tI[top[x]],tI[x]);
		change(1,tI[top[x]],tI[x],0);
		x=p[top[x]];
	}
	printf("%lld\n",ans);
}
inline void shift(int x)
{
	int ans=ask(1,tI[x],tO[x]);
	change(1,tI[x],tO[x],1);
	printf("%lld\n",sz[x]-ans);
}
inline void work(int t,int x)
{
	if(t==1)holiday(x);
	else shift(x);
}
signed main()
{
	freopen("company2.in","r",stdin);
	freopen("company2.out","w",stdout);
	n=read();
	for(int i=1;i<=4*n+5;i++)t[i].add=2;
	for(int i=2,u;i<=n;i++)u=read(),addEdge(u+1,i);
	dfs_son(1,0);
	dfs_top(1);
	build(1,n,1);
	m=read();
	for(int i=1,t,x;i<=m;i++)t=read(),x=read(),work(t,x+1);
	return 0;
}

