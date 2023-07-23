//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=5e6+5;
int n,p,a[N],b[N];
signed main()
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		b[x]+=z;b[y+1]-=z;
	}
	int ans=194927724327,cnt=0;
	for(int i=1;i<=n;i++)cnt+=b[i],ans=min(ans,cnt);
	cout<<ans;
	return 0;
}

