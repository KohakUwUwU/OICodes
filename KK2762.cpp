//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const signed N=1e5+7,P=605;
signed n,m,L,x[N];
vector<signed>a[P][P];//模数  余数 
vector<signed>val[10009];
inline int read() {
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
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
signed main()
{
	freopen("modularity.in","r",stdin);
	freopen("modularity.out","w",stdout);
	n=read(),m=read();
	L=min((signed)(sqrt(m*10009/n)+1),600);
	for(register signed i=1;i<=n;++i)x[i]=read(),val[x[i]].push_back(i);
	for(register signed i=1;i<=L;++i)//p
	{
		for(register signed j=1;j<=n;++j)//序列枚举 
		{
			a[i][x[j]%i].push_back(j);
		}
	}
	for(register signed i=1;i<=m;++i)
	{
		signed l=read(),r=read(),p=read(),v=read();
		if(p<=L)
		{
			signed lb=lower_bound(a[p][v].begin(),a[p][v].end(),l)-a[p][v].begin();
			signed rb=upper_bound(a[p][v].begin(),a[p][v].end(),r)-a[p][v].begin();
			write(rb-lb);
			printf(" ");
		}
		else
		{
			int ans=0;
			for(register signed i=v;i<=10000;i+=p)
			{
				signed lb=lower_bound(val[i].begin(),val[i].end(),l)-val[i].begin();
				signed rb=upper_bound(val[i].begin(),val[i].end(),r)-val[i].begin();
				ans+=rb-lb;
			}
			write(ans);
			printf(" ");
		}
	}
	return 0;
}
