//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,L,h[N],s[N],f[N],bst[N],q[N];
inline void RMQwl()
{
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&i-q[l]>=L)l++;
		while(l<r&&h[i]<=h[q[r-1]])r--;
		q[r++]=i;
		bst[i]=h[q[l]];
	}
}
signed main()
{
	freopen("flood.in","r",stdin);
	freopen("flood.out","w",stdout);
	scanf("%lld%lld",&n,&L);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+h[i];
	RMQwl();
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+h[i];
		if(i>=L)f[i]=min(f[i],f[i-L]+s[i]-s[i-L]-bst[i]);
	}
	printf("%lld",f[n]);
	return 0;
}

