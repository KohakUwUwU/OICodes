//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int a[N],l[N],r[N],sqt[N],n;
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))sqt[i]+=v;
}
inline int query(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))ans+=sqt[i];
	return ans;
}
signed main()
{
	freopen("arithmetic.in","r",stdin);
	freopen("arithmetic.out","w",stdout);
	int T,f;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(sqt,0,sizeof(sqt));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(2*a[i]-1<=n)l[i]=query(2*a[i]-1);
			else l[i]=query(n)-query(2*a[i]-n-1);
			add(a[i],a[i]);
		}
		for(int i=n;i>=1;i--)
		{
			if(2*a[i]-1<=n)r[i]=query(2*a[i]-1);
			else r[i]=query(n)-query(2*a[i]-n-1);
			add(a[i],a[i]);
		}
		f=1;
		for(int i=2;i<=n-1;i++)if(l[i]%(2*a[i])!=0&&r[i]%(2*a[i])!=0&&l[i]!=0&&r[i]!=0)f=0,printf("Y\n"),i=n+1;
		if(f)printf("N\n");
	}
	return 0;
}
