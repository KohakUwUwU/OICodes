//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int ok[10][20][2][2];
int f[10][20][2][2];
int cnt[114514][2],d[114514];
inline int F(int T,int p,bool lmt,bool lead0)
{
	if(!p)return 0;
	if(ok[T][p][lmt][lead0])return f[T][p][lmt][lead0];
	ok[T][p][lmt][lead0]=1;
	f[T][p][lmt][lead0]=0;
	for(int i=0;i<=(lmt?d[p]:9);++i)
	{
		if(i==T&&!(i==0&&lead0))f[T][p][lmt][lead0]+=cnt[p-1][lmt&&i==d[p]];
		f[T][p][lmt][lead0]+=F(T,p-1,lmt&&i==d[p],lead0&&i==0);
	}
	return f[T][p][lmt][lead0];
}
inline int prefix(int T,int x)
{
	memset(ok,0,sizeof(ok));
	memset(f,0,sizeof(f));
	int y=x,nD=0;
	do
	{
		d[++nD]=x%10;
		x/=10;
	}while(x);
	cnt[0][0]=1;
	cnt[0][1]=1;
	for(int p=1;p<=nD;p++)cnt[p][0]=cnt[p-1][0]*10,cnt[p][1]=y%cnt[p][0]+1;
	return F(T,nD,1,1);
}
inline void solve()
{
	int l,r;
	scanf("%lld%lld",&l,&r);
	for(int i=0;i<=9;i++)printf("%lld ",prefix(i,r)-prefix(i,l-1));
}
signed main()
{
	freopen("statistics.in","r",stdin);
	freopen("statistics.out","w",stdout);
	solve();
	return 0;
}

