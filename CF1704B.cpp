//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct Range
{
	int l,r;
	const Range operator ^(const Range x)
	{
		return (Range){max(l,x.l),min(r,x.r)};
	};
};
int n,x,a[N];
inline void judge()
{
	int cnt=0;
	Range v=(Range){a[1]-x,a[1]+x};
	for(int i=2;i<=n;i++)
	{
		v=v^(Range){a[i]-x,a[i]+x};
		if(v.l>v.r)cnt++,v=(Range){a[i]-x,a[i]+x};
	}
	cout<<cnt<<'\n';
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>a[i];
		judge();
	}
	return 0;
}

