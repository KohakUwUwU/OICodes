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

#define N (int)1e5+5
#define mod 100000007
vector<int>G[N];
int n,m,timer,cf[N*2],tI[N],tO[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	tI[u]=++timer;
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=fa)dfs_son(G[u][i],u);
	tO[u]=timer;
}
inline int lowbit(int x)
{
	return x&-x;
}
inline void addoperation(int pos,int u)
{
	while(pos<=n)cf[pos]+=u,pos+=lowbit(pos);
}
inline void add(int pos,int u)
{
	addoperation(tI[pos],u),addoperation(tO[pos]+1,-u);
}
inline int getsum(int pos)
{
	int ans=0;
	while(pos>=1)ans+=cf[pos],pos-=lowbit(pos);
	return ans; 
}
signed main()
{
	freopen("company.in","r",stdin);
	freopen("company.out","w",stdout);
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	for(int i=1;i<=m;i++)
	{
		int x=read(),w=read();
		add(x,w);
		cout<<getsum(x)<<endl;
	}
	return 0;
}

