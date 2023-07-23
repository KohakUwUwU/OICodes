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

int n,m,nD,d[20],f[20][2][2],ok[20][2][2];
inline void pre(int k)
{
	nD=0;
	while(k)
	{
		d[++nD]=k%10;
		k/=10;
	}
}
inline int F(int p,int lmt,int pre1)
{
	if(p==0)return 1;
	if(ok[p][lmt][pre1])return f[p][lmt][pre1];
	ok[p][lmt][pre1]=1;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(i==4)continue;
		if(i==3&&pre1)continue;
		f[p][lmt][pre1]+=F(p-1,lmt&&i==d[p],i==1);
	}
	return f[p][lmt][pre1];
}
inline int work(int k)
{
	memset(f,0,sizeof(f));
	memset(ok,0,sizeof(ok));
	pre(k);
	return F(nD,1,0);
}
signed main()
{
	freopen("thirteen.in","r",stdin);
	freopen("thirteen.out","w",stdout);
	n=read(),m=read();
	cout<<work(m)-work(n-1);
	return 0;
}

