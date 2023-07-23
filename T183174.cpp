//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e6+5;
int n,q,m,p,K[N],G[20],A[N],F[N];
inline void solveBF()
{
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%lld%lld",&a,&b);
		for(int j=1;j<=m;j++)scanf("%lld",&G[j]),F[j]=G[j];
		for(int j=m+1;j<=b-a+1;j++)
		{
			F[j]=0;
			for(int k=1;k<=m;k++)(F[j]+=K[k]*F[j-k])%=p;
		}
		for(int j=a;j<=b;j++)(A[j]+=F[j-a+1])%=p;
	}
	for(int i=1;i<=n;i++)printf("%lld ",A[i]%p);
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&q,&m,&p);
	for(int i=1;i<=m;i++)scanf("%lld",&K[i]);
	solveBF();
	return 0;
}

