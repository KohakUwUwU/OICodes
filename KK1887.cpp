#include<bits/stdc++.h>
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

#define int long long
#define N (int)1e5+5
#define mod 100000007
vector<int>G[N];
int n,m,timer,sz[N],son[N],top[N],dfs[N],dfn[N],state[N*2],father[N];
inline int lowbit(int u)
{
	return u&(-u);
}
inline void add(int pos,int u)
{
	while(pos<=n)
	{
		state[pos]+=u;
		pos+=lowbit(pos);
	}
}
inline int getsum(int pos)
{
	int ans=0;
	while(pos>=1)ans+=state[pos],pos-=lowbit(pos);
	return ans;
}
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0,father[u]=fa;
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
inline void work()
{
	int x=read(),w=read(),output=0;
	add(dfn[x],w);
	while(x)
	{
		output+=getsum(dfn[x])-getsum(dfn[top[x]]-1);
		output%=mod;
		x=father[top[x]];
	}
	cout<<output<<'\n';
}
signed main()
{
	freopen("company.in","r",stdin);
	freopen("company.out","w",stdout);
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	dfs_top(1,0);
	for(int i=1;i<=m;i++)work();
	return 0;
}

