//And int that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],cf[N],bit[N<<1];
inline int lowbit(int &x)
{
	return x&(-x);
}
inline void build()
{
	for(int i=1;i<=n;i++)bit[i]+=cf[i],bit[i+lowbit(i)]+=bit[i];
}
inline void Add(int p,int x)
{
	while(p<=n)bit[p]+=x,p+=lowbit(p);
}
inline int Sum(int x)
{
	int ans=0;
	while(x)ans+=bit[x],x-=lowbit(x);
	return ans;
}
signed main()
{
	scanf("%lld%ld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	cf[1]=a[1];
	for(int i=2;i<=n;i++)cf[i]=a[i]-a[i-1];
	build();
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;
		scanf("%lld%lld",&opt,&x);
		if(opt==1)scanf("%lld%lld",&y,&k),Add(x,k),Add(y+1,-k);
		else printf("%lld\n",Sum(x));
	}
	return 0;
}
