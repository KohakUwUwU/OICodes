//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,a[N],f[N];
signed main()
{
	freopen("pond.in","r",stdin);
	freopen("pond.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mx1=a[1],mx2=a[n];
	for(int i=2;i<=n;i++)
	{
		if(a[i]<mx1)f[i]++;
		mx1=max(mx1,a[i]);
	}
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<mx2)f[i]++;
		mx2=max(mx2,a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(f[i]==2)cnt++;
	cout<<cnt;
	return 0;
}

