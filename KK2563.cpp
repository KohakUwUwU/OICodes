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

#define N (int)1e5+5
vector<int>G[N];
int n,m,sz[N],son[N],top[N],d[N],father[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0,d[u]=d[fa]+1,father[u]=fa;
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
	if(u==son[fa])top[u]=top[fa];
	else top[u]=u;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_top(v,u);
	}
}
inline int query(int u,int v)
{
	int cnt=1;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])v=father[top[v]];
		else u=father[top[u]];
		++cnt;
	}
	return cnt;
}
int main()
{
	freopen("pathdecomposition.in","r",stdin);
	freopen("pathdecomposition.out","w",stdout);
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	dfs_top(1,0);
	m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),cout<<query(u,v)<<' ';
	return 0;
}

