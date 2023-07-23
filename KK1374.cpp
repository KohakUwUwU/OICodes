//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

//f[p][pre1][pre2][lead][lmt]
//当前状态有多少个回文数
//p:尾部p位数待填写 
//pre1:当前位的左侧第二位已填写pre1
//pre2:当前位的左侧第二位已填写pre2 
//lead:当前位的左侧已经填写的有效位数 
//0 表示左侧未填写非零数字 
//1 表示左侧恰好填写1个非零数字 
//2 表示左侧已填写不少于2个有效数字 
//lmt: 尾部p位数大小是否受限制 
//0 可以无限制随意填写 
//1 不能超过d[]尾部p位数 
int f[20][10][10][3][2];
bool ok[20][10][10][3][2];
int d[100];
inline int F(int p,int pre1,int pre2,int lead,int lmt)
{
	if(!p)return 1;
	if(ok[p][pre1][pre2][lead][lmt])return f[p][pre1][pre2][lead][lmt];
	ok[p][pre1][pre2][lead][lmt]=1;
	f[p][pre1][pre2][lead][lmt]=0;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(lead>=1&&i==pre1)continue;
		if(lead>=2&&i==pre2)continue;
		int L=(i||lead?lead+1:0);
		if(L>2)L=2;
		f[p][pre1][pre2][lead][lmt]+=F(p-1,i,pre1,L,lmt&&i==d[p]);
	}
	return f[p][pre1][pre2][lead][lmt];
}
inline int prefix(int x)
{
	memset(f,0,sizeof(f));
	memset(ok,0,sizeof(ok));
	int nD=0;
	do
	{
		d[++nD]=x%10;
		x/=10;
	}while(x);
	return F(nD,0,0,0,1);
}
inline void solve()
{
	int l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",prefix(r)-prefix(l-1));
}
signed main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	solve();
	return 0;
}

