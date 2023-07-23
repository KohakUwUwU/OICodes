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

const int N=2e5+5;
int n,ans,fa[N],sz[N];
vector<pair<int,int> >p;
vector<int>G[N];
inline int Find(int x)
{
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline void Merge(int x,int y)
{
	fa[Find(x)]=Find(y);
}
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
//	cout<<u<<'\n';
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
signed main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c==1)p.push_back(make_pair(a,b));
		else Merge(a,b),addEdge(a,b);
	}
//	for(int i=1;i<=n;i++)cout<<G[i].size()<<' ';
//	cout<<'\n';
	for(int i=1;i<=n;i++)if(fa[i]==i)dfs(i,0),ans+=sz[i]*(sz[i]-1)/2;
//	for(int i=1;i<=n;i++)cout<<sz[i]<<' ';
//	cout<<endl;
	int max_delta=0;
	for(int i=0;i<p.size();i++)
	{
		int u=p[i].first,v=p[i].second;
		u=Find(u),v=Find(v);
		int sz1=sz[u],sz2=sz[v];
		max_delta=max((sz1+sz2)*(sz1+sz2-1)/2-sz1*(sz1-1)/2-sz2*(sz2-1)/2,max_delta);
	}
	cout<<n*(n-1)/2-(ans+max_delta);
	return 0;
}
