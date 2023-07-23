//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e6+9;
int n,m,p,q,nxt[N],ans[N];
inline int root(int x)
{
	return (nxt[x]==x)?x:(nxt[x]=root(nxt[x]));
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for(int i=1;i<=n;i++)nxt[i]=i;
	for(int clr=m;clr>=1;clr--)
	{
		int l=(clr*p+q)%n+1;
		int r=(clr*q+p)%n+1;
		if(l>r)swap(l,r);
		for(int id=root(r);id>=l;id=root(id))ans[id]=clr,nxt[id]=root(id-1);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}

