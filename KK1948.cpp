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

const int N=2e5+7;
int n,a[N],p[N],nxt[N],pre[N],ans[N];
signed main()
{
	freopen("heroes.in","r",stdin);
	freopen("heroes.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),p[a[i]]=i;
	for(int i=1;i<=n;i++)nxt[i]=i+1,pre[i]=i-1;
	for(int i=1;i<=n;i++)
	{
		ans[p[i]]=nxt[p[i]];
		nxt[pre[p[i]]]=nxt[p[i]];
		pre[nxt[p[i]]]=pre[p[i]];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
