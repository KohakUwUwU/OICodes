//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=3e5+5;
int n,m;
int bit[2*N],id[N];
inline int lowbit(int &x)
{
	return x&-x;
}
inline int Sum(int p)
{
	int ans=0;
	while(p)ans+=bit[p],p-=lowbit(p);
	return ans;
}
inline int Find(int x)
{
	int p=0,lo=20;
	while(lo>=0)
	{
		if(p+(1<<lo)<=n+m)
		{
			int ans=Sum(p+(1<<lo));
			if(ans<=x)p+=(1<<lo);
		}
		lo--;
	}
	return p;
}
inline void Add(int p,int x)
{
	while(p<=n+m)bit[p]+=x,p+=lowbit(p);
}
inline void printID()
{
	for(int i=1;i<=10;i++)printf("%lld ",id[i]);
	puts(" ");
}
inline void printBIT()
{
	for(int i=1;i<=20;i++)printf("%lld ",bit[i]);
	puts(" ");
}
signed main()
{
	freopen("premiere4.in","r",stdin);
	freopen("premiere4.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)bit[i]+=1,bit[i+lowbit(i)]+=bit[i],id[i]=i;
	for(int i=n+1;i<=n+m;i++)bit[i+lowbit(i)]+=bit[i];
	for(int i=1;i<=m;i++)
	{
		int q;
		scanf("%lld",&q);
		int p=Find(q-1)+1;
		Add(p,-1);
		Add(n+i,1);
		id[n+i]=id[p];
		printf("%lld ",id[p]);
		id[p]=0;
//		cout<<endl;
//		printID();printBIT();
	}
	return 0;
}

