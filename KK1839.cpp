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

struct query
{
	int id,clr;
};
const int N=2e5+5;
int n,m,timer;
int p[N][30],sz[N],son[N],d[N],tI[N],tO[N],dfn[N],cnt[N],ans[N];
vector<int>G[N];
vector<query>q[N];
set<int>S[N*2];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline int LA(int u,int level)
{
	int i=21;
	while(level)
	{
		if(level>=(1<<i))u=p[u][i],level-=1<<i;
		i--;
	}
	return u;
}
inline void dfs_sz_son(int u)
{
	dfn[++timer]=u,tI[u]=timer;
	sz[u]=1,son[u]=0,d[u]=d[p[u][0]]+1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs_sz_son(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
	tO[u]=timer;
}
inline void aNode(int u,bool tag)
{
	if(tag)cnt[d[u]]++;
	else cnt[d[u]]--;
}
inline void aTree(int u,int tag)
{
	for(int i=tI[u];i<=tO[u];i++)
	{
		aNode(dfn[i],tag);
	}
}
inline void dfs_work(int u,bool hvy)
{
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])dfs_work(G[u][i],0);
	if(son[u])dfs_work(son[u],1);
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])aTree(G[u][i],1);
	aNode(u,1);
	for(int i=0;i<q[u].size();i++)ans[q[u][i].id]=cnt[d[u]+q[u][i].clr]-1;
	if(!hvy)aTree(u,0);
}
signed main()
{
	freopen("bro.in","r",stdin);
	freopen("bro.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)p[i][0]=read(),addEdge(p[i][0],i);
	for(int i=1;i<=21;i++)for(int j=1;j<=n;j++)p[j][i]=p[p[j][i-1]][i-1];
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),k=read();
		q[LA(u,k)].push_back((query){i,k});
	}
	for(int i=1;i<=n;i++)if(!p[i][0])dfs_sz_son(i);
	for(int i=1;i<=n;i++)if(!p[i][0])dfs_work(i,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

