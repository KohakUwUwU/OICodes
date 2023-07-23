//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N=2e5+5;
int n,s,L,h[N],a[N]; 
inline bool check(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((h[i]+a[i]*x)>=L)ans+=h[i]+a[i]*x;
		if(ans>=s)break;
	}
	if(ans>=s)return false;
	return true;
}
signed main()
{
	cin>>n>>s>>L;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=0,r=1e18+15;
	while(l!=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	cout<<l;
	return 0;
}

