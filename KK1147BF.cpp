//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
int n,k,x[N];
signed main()
{
	freopen("xjj.in","r",stdin);
	freopen("xjjBF.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n-k+1;i++)
	{
		int ans=114514114514;
		for(int j=i;j<=i+k-1;j++)ans=min(ans,x[j]);
		printf("%lld ",ans);
	}
	return 0;
}

