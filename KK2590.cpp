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

const int N=1e5+7;
int m,n,a[N],ans[N];
struct point
{
	int x,y;
}p[N],s[N];
struct query
{
	int u,v,rk;
}q[N];
#define f(x,y) for(int i=x;i<=y;i++)
inline bool P(point x,point y)
{
	return x.x>y.x||x.x==y.x&&x.y<y.y;
}
inline bool Q(query x,query y)
{
	return x.u>y.u||x.u==y.u&&x.v<y.v;
}
signed main()
{
	freopen("corner.in","r",stdin);
	freopen("corner.out","w",stdout);
	n=read(),m=read();
	f(1,n)p[i].x=read();
	f(1,n)p[i].y=read();
	f(1,m)q[i].u=read();
	f(1,m)q[i].v=read();
	f(1,m)q[i].rk=i;
	sort(p+1,p+1+n,P);sort(q+1,q+1+m,Q);
	int cnt=0,j=1;
	for(int i=1;i<=m;i++)
	{
		while(j<=n&&p[j].x>q[i].u){while(cnt&&p[j].y>=s[cnt].y)cnt--;s[++cnt]=p[j++];}
		int l=1,r=cnt,res=1145141145;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(s[mid].y>q[i].v)res=s[mid].x,l=mid+1;
			else r=mid-1;
			ans[q[i].rk]=(res==1145141145?0:res);
		}
	}
	f(1,m)cout<<ans[i]<<' ';
	return 0;
}

