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

const int N=5e5+7;
int n,a[N],st[N],top,cnt;
inline int Find(int t)
{
	int p=0;
	for(int i=20;i>=0;i--)
	{
		if(p+(1<<i)>top||a[st[p+(1<<i)]]<=t)continue;
		p+=(1<<i);
	}
	return p;
}
inline void print_st()
{
	cout<<"st:  ";
	for(int i=1;i<=top;i++)cout<<st[i]<<' ';
	cout<<'\n';
	cout<<"top:"<<top<<"  cnt:"<<cnt<<'\n';
}
signed main()
{
	freopen("u.in","r",stdin);
	freopen("u.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int wP=Find(a[i]),iP=Find(a[i]-1);
		cnt+=top-wP;
		if(wP)cnt++;
		st[top=iP+1]=i;
//		print_st();
	}
	cout<<cnt;
	return 0;
}

