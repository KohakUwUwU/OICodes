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

const int N=2001;
const int mod=998244353;
int n,a[N],b[N],yh[N][N];
inline void work(int k)
{
	b[k]=a[k];
	int neg=1;
	for(int i=k;i>=0;i--,((n-k)%2==1)&&(neg=-neg))
	{
		a[i]-=yh[k][i]*neg*b[k]%mod;
		a[i]=(a[i]%mod+mod)%mod;
//		for(int j=0;j<=n;j++)cout<<a[j]<<' ';
//		cout<<'\n';
	}
}
signed main()
{
	n=read();
	for(int i=0;i<=n;i++)cin>>a[i];
	yh[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		yh[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			yh[i][j]%=mod;
		}
	}
	for(int i=n;i>=0;i--)
	{
		work(i);
	}
	for(int i=0;i<=n;i++)
	{
		b[i]%=mod;
		while(b[i]>=mod)b[i]-=mod;
		while(b[i]<0)b[i]+=mod;
		cout<<b[i]<<' ';
	}
	return 0;
}
