//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
const int INF=11514114514;
int n,k,x[N*8][20],lo=20;
signed main()
{
	freopen("xjj.in","r",stdin);
	freopen("xjjSOLVE.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i][0]);
	for(int i=1;i<=20;i++)for(int j=1;j<=n-(1<<i)+1;j++)x[j][i]=min(x[j][i-1],x[j+(1<<(i-1))][i-1]);
	while(k<=(1<<lo))lo--;
	for(int i=1;i<=n-k+1;i++)printf("%lld ",min(x[i][lo],x[i+k-(1<<lo)][lo]));
	return 0;
}

