//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
const int INF=11514114514;
int n,k,x[N*7][20],lo=20;
signed main()
{
	freopen("xjj.in","r",stdin);
	freopen("xjj.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(n<=1000)
	{
		int x[N]={};
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n-k+1;i++)
		{
			int ans=114514114514;
			for(int j=i;j<=i+k-1;j++)ans=min(ans,x[j]);
			printf("%lld ",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&x[i][0]);
	for(int i=1;i<=20;i++)for(int j=1;j<=n-(1<<i)+1;j++)x[j][i]=min(x[j][i-1],x[j+(1<<(i-1))][i-1]);
	while(k<=(1<<lo))lo--;
	for(int i=1;i<=n-k+1;i++)printf("%lld ",min(x[i][lo],x[i+k-(1<<lo)][lo]));
	return 0;
}

