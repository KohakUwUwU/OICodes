//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
int n,P,Q,x[N],s[N],rs[N],q[N],mn[N];
signed main()
{
	freopen("stock.in","r",stdin);
	freopen("stock.out","w",stdout);
	scanf("%lld%lld%lld",&n,&P,&Q);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),s[i]=s[i-1]+x[i];
	for(int i=Q;i<=n;i++)rs[i]=s[i]-s[i-Q];
	int l=0,r=0;
	for(int R=Q;R<=n;R++)
	{
		while(l<r&&R-q[l]>=P-1)l++;
		while(l<r&&rs[R]<=rs[q[r-1]])r--;
		q[r++]=R;
		mn[R]=rs[q[l]];
	}	
	int ans=0;
	for(int R=P+Q;R<=n;R++)ans=max(ans,s[R]-s[R-P-Q]-mn[R-1]);
	cout<<ans;
	return 0;
}

