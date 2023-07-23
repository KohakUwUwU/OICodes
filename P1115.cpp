//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
int n,a[N],s,mx=-114514114514,mn;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s+=a[i];
		mx=max(mx,s-mn);
		mn=min(mn,s);
	}
	printf("%lld",mx);
	return 0;
}

