//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e6+5;
int n,h[N],t[N],rr[N],c[N],x[N],f[N];
signed main()
{
	freopen("dorm3.in","r",stdin);
//	freopen("dorm3BF.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&h[i],&x[i],&c[i]),t[i]=t[i-1]+x[i],rr[i]=rr[i-1]+h[i]*x[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=0x3f3f3f3f;
		for(int j=0;j<i;j++)
		f[i]=min(-h[i]*t[j]+rr[j]+f[j]+c[i]+h[i]*t[i-1]-rr[i-1],f[i]);
//		f[i]=min(f[j]+(t[i-1]-t[j])*h[i]-rr[i-1]+rr[j]+c[i],f[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}

