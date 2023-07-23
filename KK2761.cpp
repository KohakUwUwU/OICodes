//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int SZ=400,N=5e4+5;
int ans[SZ][SZ],L;
int n,m,x[N];
inline void precompute()
{
	for(int p=1;p<=L;p++)for(int i=1;i<=n;i++)ans[p][i%p]+=x[i];
}
inline void upd(int id,int v)
{
	for(int p=1;p<=L;p++)ans[p][id%p]+=v-x[id];
	x[id]=v;
}
inline void solve()
{
	L=sqrt(n*m/(2*n+m))+1;
	precompute();
	for(int iQ=1;iQ<=m;iQ++)
	{
		char op;
		int p,v;
		cin>>op>>p>>v;
		if(op=='Q')
		{
			if(p<=L)printf("%lld ",ans[p][v]);
			else 
			{
				int sum=0;
				for(int i=v;i<=n;i+=p)sum+=x[i];
				printf("%lld ",sum);
			}
		}
		else upd(p,v);
	}
}
signed main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	solve();
	return 0;
}

