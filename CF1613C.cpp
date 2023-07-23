//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=105;
int t,n,h,a[N];
inline bool check(int k)
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(ans>=h)return true;
		ans+=min(a[i+1]-a[i],k);
//		cout<<ans<<' ';
	}
	ans+=k;
//	cout<<ans<<'\n';
	if(ans>=h)return true;
	else return false;
}
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>h;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=1e18;
		while(r!=l)
		{
			int mid=(l+r>>1);
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}

