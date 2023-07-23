//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
int n,x[N],mx,ans[N],p[N];
signed main()
{
	freopen("heroes.in","r",stdin);
	freopen("heroes.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),p[x[i]]=i;
	for(int i=n;i>=1;i--)
	{
		if(p[i]<mx)ans[p[i]]=mx;
		mx=max(mx,p[i]);
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}

