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

int n,m,nD,d[20],f[20][2][2][11],ok[20][2][2][11];
inline void pre(int k)
{
	nD=0;
	while(k)
	{
		d[++nD]=k%10;
		k/=10;
	}
}
inline int F(int p,int lmt,int lead0,int pre)
{
	if(p==0)return 1;
	if(ok[p][lmt][lead0][pre])return f[p][lmt][lead0][pre];
	ok[p][lmt][lead0][pre]=1;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(!lead0&&abs(pre-i)<2)continue;
		f[p][lmt][lead0][pre]+=F(p-1,lmt&&d[p]==i,lead0&&i==0,i);
	} 
	return f[p][lmt][lead0][pre];
}
inline int work(int k)
{
	memset(f,0,sizeof(f));
	memset(ok,0,sizeof(ok));
	pre(k);
	return F(nD,1,1,11);
}
signed main()
{
	freopen("volatility.in","r",stdin);
	freopen("volatility.out","w",stdout);
	n=read(),m=read();
	cout<<work(m)-work(n-1);
	return 0;
}

