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

const int N=1e5+5;
int n,p[N];
double num[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline void dfs(int u,int fa)
{
	num[u]+=num[fa];
	for(int i=0;i<G[u].size();i++)dfs(G[u][i],u);
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	num[1]=1;
	for(int i=2;i<=n;++i)p[i]=read(),num[i]=1,addEdge(p[i],i);
	dfs(1,0);
	double ans=0.0;
	for(int i=1;i<=n;i++)ans+=1.0/double(num[i]);
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}

