//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int f[20][165][165][2];
bool ok[20][165][165][2];
int d[114514];
inline int F(int&mod,int p,int s,int r,int lmt)
{
	if(!p)return !s&&!r;
	if(ok[p][s][r][lmt])return f[p][s][r][lmt];
	ok[p][s][r][lmt]=1;
	f[p][s][r][lmt]=0;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(i>s)break;
		if(p*9<s)break;
		f[p][s][r][lmt]+=F(mod,p-1,s-i,(r*10+i)%mod,lmt&&i==d[p]);
	}
	return f[p][s][r][lmt];
}
inline int prefix(int x)
{
	int nD=0;
	do
	{
		d[++nD]=x%10;
		x/=10;
	}while(x);
	int res=0;
	for(int mod=1;mod<=nD*9;mod++)res+=F(mod,nD,mod,0,1),memset(ok,0,sizeof(ok));
	return res;
}
inline void solve()
{
	int l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld",prefix(r)-prefix(l-1));
}
signed main()
{
	freopen("multiple.in","r",stdin);
	freopen("multiple.out","w",stdout);
	solve();
	return 0;
}

