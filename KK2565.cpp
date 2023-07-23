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

const int N=1<<21;
int n,Q,timer,a[N],tI[N],tO[N],dfn[N],stmin[N][20],stmax[N][20];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
	dfn[++timer]=u,tI[u]=timer;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v!=fa)dfs(v,u);
	}
	tO[u]=timer;
}
inline int getMin(int u)
{
	int x=tI[u],y=tO[u],len=(int)(log2(y-x+1));
	return min(stmin[x][len],stmin[y-(1<<len)][len]);
}
inline int getMax(int u)
{
	int x=tI[u],y=tO[u],len=(int)(log2(y-x+1));
	return max(stmax[x][len],stmax[y-(1<<len)][len]);
}
signed main()
{
	n=read(),Q=read();
	for(int i=1;i<=n;i++)cin>>a[i],stmin[i][0]=a[i],stmax[i][0]=a[i];
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs(1,0);
	for(int i=1;i<=19;i++)for(int j=1;j<=n;j++)stmin[j][i]=min(stmin[j][i-1],stmin[j+(1<<i-1)][i-1]),stmax[j][i]=max(stmax[j][i-1],stmax[j+(1<<i-1)][i-1]);
	for(int i=1;i<=Q;i++)
	{
		int opt=read(),u,x;
		if(opt==1)u=read(),cout<<getMin(u);
		if(opt==2)u=read(),cout<<getMax(u);
		if(opt==3)u=read(),x=read(),cout<<1;
	}
	return 0;
}
